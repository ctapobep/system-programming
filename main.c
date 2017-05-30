#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef unsigned char *bytes;

void show_bytes(bytes aBytes, int size) {
    for (int i = 0; i < size; i++) printf("%.2x ", aBytes[i]);
    printf("\n");
}
int bis(int x, int m) {
    return x | m;
}
int bic(int x, int m) {
    return ~(~x | m);
}

int main() {
    const char *s = "abcd";

    show_bytes((bytes)s, strlen(s));
    return 0;
}

