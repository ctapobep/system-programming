#include "csapp.h"

ssize_t rio_readn(int fd, void *usrbuf, size_t n);
ssize_t rio_writen(int fd, void *usrbuf, size_t n);

//int main(){return 0;}
//void rio_readinitb(rio_t *rp, int fd);
//ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);
//ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);