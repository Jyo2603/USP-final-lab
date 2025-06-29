#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR *d = opendir(".");
    struct dirent *e;
    struct stat s;

    while ((e = readdir(d))) {
        stat(e->d_name, &s);
        printf("%lu %lu %u %ld %s\n",
               s.st_ino, s.st_nlink, s.st_uid, s.st_size, e->d_name);
    }
    closedir(d);
}
