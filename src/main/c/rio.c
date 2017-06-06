#include "csapp.h"
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <memory.h>

ssize_t rio_readn(int fd, void *usrbuf, size_t n) {
    ssize_t nleft = n;
    ssize_t nread;
    char *bufp = usrbuf;
    while(nleft > 0) {
        if((nread = read(fd, bufp, nleft)) < 0) {
            if(errno == EINTR) nread = 0;
            else               return -1;
        } else if (nread == 0) break; /* EOF */
        nleft -= nread;
        bufp += nread;
    }
    return n - nleft;/* Return >= 0 */
}
ssize_t rio_writen(int fd, void *usrbuf, size_t n) {
    ssize_t nleft = n;
    ssize_t nwritten;
    char *bufp = usrbuf;
    while(nleft > 0) {
        if((nwritten = write(fd, bufp, nleft)) < 0) {
            if(errno == EINTR) nwritten = 0; /* Interrupted by sig handler return, re-write */
            else               return -1; /* errno set by read() */
        } else if(nwritten == 0) break;
        nleft -= nwritten;
        bufp += nwritten;
    }
    return n;
}

static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n) {
    while(rp->rio_cnt <= 0) {/* Refill if buf is empty */
        rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));
        if(rp->rio_cnt < 0 && errno != EINTR) return -1;
        else if (rp->rio_cnt == 0)            return 0;//EOF
        else                                  rp->rio_bufptr = rp->rio_buf;//reset buffer ptr
    }
    ssize_t cnt = n;
    if(rp->rio_cnt < n) cnt = rp->rio_cnt;
    memcpy(usrbuf, rp->rio_bufptr, cnt);
    rp->rio_bufptr += cnt;
    rp->rio_cnt -= cnt;
    return cnt;
}

ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen) {
    int n;
    ssize_t rc = 0;
    char c, *bufp = usrbuf;
    for(n = 1; n < maxlen; n++) {
        if((rc = rio_read(rp, &c, 1)) == 1) {
            *bufp++ = c;
            if(c == '\n') break;
        } else if(rc == 0) {/* EOF, some data was read */
            if(n == 1) return 0;
            else break;
        } else return -1;
    }
    *bufp = 0;
    return n;
}
void rio_readinitb(rio_t *rp, int fd) {
    rp->rio_fd = fd;
    rp->rio_cnt = 0;
    rp->rio_bufptr = rp->rio_buf;
}
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n) {
    ssize_t nread = 0;
    ssize_t nleft = n;
    char *bufp = usrbuf;
    while(nleft > 0) {
        if((nread = rio_read(rp, bufp, nleft)) < 0) {
            if(errno == EINTR) return 0;
            else return -1;
        }
        nleft = n - nread;
        bufp += nread;
    }
    return (n - nleft);
}

