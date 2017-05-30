#include "csapp.h"
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
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

//void rio_readinitb(rio_t *rp, int fd);
//ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);
//ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);