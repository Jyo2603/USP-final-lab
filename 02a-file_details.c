#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

int main() {
    struct stat s;
    stat("shared.txt", &s);
    printf("Size: %lld\n", (long long)s.st_size);
    printf("Perm: %o\n", s.st_mode & 0777);
    printf("Links: %hu\n", s.st_nlink);
    printf("UID: %d\n", s.st_uid);
    printf("Modified: %s", ctime(&s.st_mtime));
}
