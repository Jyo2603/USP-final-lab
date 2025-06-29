#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("shared.txt", O_RDONLY);
    char buf[11] = {0};
    if (fork() == 0) {
        read(fd, buf, 10);
        write(1, "Child: ", 7);
    } else {
        sleep(1);
        read(fd, buf, 10);
        write(1, "Parent: ", 8);
    }
    write(1, buf, 10);
}
