#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "rio.h"

#define DEF_MODE   S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH
//#define DEF_UMASK  S_IWGRP|S_IWOTH

int* filemodes() {
    static int filemodes[] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH ,S_IXOTH};
    return filemodes;
}
void readfile(/*char* filename*/) {
//    int fd = open(filename, O_RDONLY, 0);
    char c;
    while(read(STDIN_FILENO, &c, 1) != 0) write(STDOUT_FILENO, &c, 1);
    exit(0);
//    int buffer_size = 128;
//    char buffer[buffer_size];
//    read(fd, buffer, buffer_size);
}

int main() {
    int *fmodes = filemodes(); for(int i = 0; i < 9; i++) printf("%d ", fmodes[i]);

    int fd = open("./target/tmpfile_by_c.txt", O_RDWR | O_CREAT | O_TRUNC, DEF_MODE);
    close(fd);
    printf("\n%d ", fd);
//    readfile();
    return 0;
}

