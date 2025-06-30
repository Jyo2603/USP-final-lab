#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int f = open("test.txt", O_WRONLY | O_TRUNC);
    int d1 = dup(f);
    write(d1, "Hello from dup\n", 15);

    int d2 = dup2(f, 7);
    write(d2, "Hello from dup2\n", 16);

    close(f);
    close(d1);
    close(d2);
    return 0;
}

/* echo "" > test.txt
gcc dup_dup2.c -o dup_dup2
./dup_dup2
cat test.txt */
