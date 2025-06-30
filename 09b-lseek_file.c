#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int f = open("test.txt", O_RDONLY);
    char b[21]; struct stat s;

    read(f, b, 20); b[20] = 0;
    puts(b);

    lseek(f, 10, SEEK_SET);
    read(f, b, 20); b[20] = 0;
    puts(b);

    lseek(f, 10, SEEK_CUR);
    read(f, b, 20); b[20] = 0;
    puts(b);

    fstat(f, &s);
    printf("%lld\n", (long long)s.st_size);
}
