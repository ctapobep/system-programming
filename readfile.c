#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define DEF_MODE   S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH
//#define DEF_UMASK  S_IWGRP|S_IWOTH

int* filemodes() {
    static int filemodes[] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH ,S_IXOTH};
    return filemodes;
}

int main() {
    char str[4];

    int *fmodes = filemodes();
    for(int i = 0; i < 9; i++) printf("%d ", fmodes[i]);

    int fd = open("/tmp/tmpfile_by_c", O_RDWR | O_CREAT | O_TRUNC, DEF_MODE);
    close(fd);
    printf("\n%d ", fd);
    return 0;
}

