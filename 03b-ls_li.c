#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    DIR *d = opendir(".");
    struct dirent *e;
    struct stat s;

    while ((e = readdir(d))) {
        stat(e->d_name, &s);
        printf("%ld %lu %ld %lu %s\n",
            s.st_size, s.st_nlink, s.st_atime, s.st_ino, e->d_name);
    }

    closedir(d);
}
