#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("input.txt", O_RDONLY);
    char ch;
    off_t pos = lseek(fd, 0, SEEK_END);

    while (pos-- > 0) {
        lseek(fd, pos, SEEK_SET);
        read(fd, &ch, 1);
        write(1, &ch, 1);
    }

    close(fd);
}
