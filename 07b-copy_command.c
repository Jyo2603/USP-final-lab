#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 3) return 1;

    int src = open(argv[1], O_RDONLY);
    int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    char buf[100];
    int n;

    while ((n = read(src, buf, 100)) > 0)
        write(dest, buf, n);

    close(src);
    close(dest);
}

/* ✅ How to run:
echo "Hello from source file." > src.txt
gcc copy.c -o copy
./copy src.txt dest.txt
cat dest.txt */
