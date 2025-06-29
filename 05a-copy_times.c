#include <stdio.h>
#include <utime.h>
#include <sys/stat.h>

int main() {
    struct stat s;
    if (stat("source.txt", &s)) 
      return perror("stat"), 1;
  
    struct utimbuf t = {s.st_atime, s.st_mtime};
  
    if (utime("dest.txt", &t)) 
      return perror("utime"), 1;
  
    puts("Times copied.");
}
