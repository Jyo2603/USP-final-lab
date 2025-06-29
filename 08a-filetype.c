#include <stdio.h>
#include <sys/stat.h>

int main(int c, char *v[]) {
    struct stat s;
    if (c < 2 || lstat(v[1], &s)) return puts("Usage: ./a.out <file>");

    if (S_ISREG(s.st_mode)) puts("Regular");
    else if (S_ISDIR(s.st_mode)) puts("Directory");
    else if (S_ISLNK(s.st_mode)) puts("Link");
    else if (S_ISCHR(s.st_mode)) puts("Char Dev");
    else if (S_ISBLK(s.st_mode)) puts("Block Dev");
    else if (S_ISFIFO(s.st_mode)) puts("FIFO");
    else if (S_ISSOCK(s.st_mode)) puts("Socket");
    else puts("Unknown");
}

/* echo "hello" > file.txt
mkdir mydir
ln -s file.txt mylink
mkfifo myfifo
python3 -c 'import socket as s;s.socket(s.AF_UNIX).bind("mysock")'
sudo mknod myblock b 1 5
sudo mknod mychar c 1 7

./filetype file.txt
./filetype mydir
./filetype mylink
./filetype myfifo
./filetype mysock
sudo ./filetype myblock
sudo ./filetype mychar */
