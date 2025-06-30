#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int status;
    pid_t c1 = fork();

    if (c1 == 0) {
        printf("Child 1 (PID %d)\n", getpid());
        return 1;
    }

    pid_t c2 = fork();
    if (c2 == 0) {
        printf("Child 2 (PID %d)\n", getpid());
        return 2;
    }

    wait(&status);
    printf("wait: Child exited with %d\n", WEXITSTATUS(status));

    waitpid(c2, &status, 0);
    printf("waitpid: Child 2 exited with %d\n", WEXITSTATUS(status));

    return 0;
}
