#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int f = open("test.txt", O_RDWR);
    struct flock l = {F_WRLCK, SEEK_END, -100, 100};
    fcntl(f, F_GETLK, &l);

    if (l.l_type != F_UNLCK) {
        printf("Already locked by PID: %d\n", l.l_pid);
        return 0;
    }

    fcntl(f, F_SETLK, &l);

    char b[51] = {};
    lseek(f, -50, SEEK_END);
    read(f, b, 50);
    printf("Last 50 bytes:\n%s\n", b);

    l.l_type = F_UNLCK;
    fcntl(f, F_SETLK, &l);
    printf("Region unlocked.\n");
    close(f);
}
