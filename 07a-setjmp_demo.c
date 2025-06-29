#include <stdio.h>
#include <setjmp.h>

jmp_buf jb;

int main() {
    static int s = 1;
    int a = 2;
    register int r = 3;
    volatile int v = 4;

    if (setjmp(jb)) {
        printf("After: s=%d a=%d r=%d v=%d\n", s, a, r, v);
        return 0;
    }

    s = 9; a = 9; r = 9; v = 9;
    printf("Before: s=%d a=%d r=%d v=%d\n", s, a, r, v);

    longjmp(jb, 1);
}
