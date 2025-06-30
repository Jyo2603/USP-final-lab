// 🔹 add.c (Parent)

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int c, char *v[]) {
    if (c != 3) return printf("Usage: ./add a b\n"), 1;

    if (fork() == 0)
        execl("./sum", "sum", v[1], v[2], NULL);
    else
        wait(NULL);

    return 0;
}

// 🔹 sum.c (Child)

#include <stdio.h>
#include <stdlib.h>

int main(int c, char *v[]) {
    printf("Sum: %d\n", atoi(v[1]) + atoi(v[2]));
    return 0;
}

/* ✅ To Compile and Run:
gcc add.c -o add
gcc sum.c -o sum
./add 10 20 */
