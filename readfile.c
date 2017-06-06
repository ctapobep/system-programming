#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "rio.h"

#define DEF_MODE   S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH
//#define DEF_UMASK  S_IWGRP|S_IWOTH


int main() {
    int fd = open("./target/tmpfile_by_c.txt", O_RDWR | O_CREAT | O_TRUNC, DEF_MODE);
    char to_write[] = "put some string here";
    printf("[Wrote]: %s\n", to_write);
    size_t length = sizeof(to_write);
    rio_writen(fd, to_write, length);
    close(fd);

    fd = open("./target/tmpfile_by_c.txt", O_RDONLY, 0);
    char read[length];
    rio_t rp;
    rio_readinitb(&rp, fd);
    rio_readlineb(&rp, read, length);

    close(fd);
    printf("[Read ]: %s \n", read);
    return 0;
}

int* filemodes() {
    static int filemodes[] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH ,S_IXOTH};
    return filemodes;
}
void readfile() {
    char c;
    while(read(STDIN_FILENO, &c, 1) != 0) write(STDOUT_FILENO, &c, 1);
}