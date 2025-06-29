#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_RDWR);
    char buf[6];
    int n = read(fd, buf, 5);
    buf[n] = 0;
    lseek(fd, 0, SEEK_END);
    dup2(fd, 1);
    printf("%s", buf);
    close(fd);
}
