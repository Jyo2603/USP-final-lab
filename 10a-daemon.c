#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>   

int main() {
    if (fork())
        exit(0);

    setsid();
    chdir("/");
    umask(0);

    int f = open("/dev/null", O_RDWR);
    dup2(f, 0);
    dup2(f, 1);
    dup2(f, 2);

    while (1)
        sleep(15);
}
