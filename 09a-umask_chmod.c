#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    umask(022);
    open("demo.txt", O_CREAT, 0666);
  
    struct stat s;
    stat("demo.txt", &s);
    printf("%o\n", s.st_mode & 0777);
  
    chmod("demo.txt", 0704);
    stat("demo.txt", &s);
    printf("%o\n", s.st_mode & 0777);
}
