#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>  

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child (PID %d) exiting...\n", getpid());
        return 0;
    } else {
        printf("Parent (PID %d) sleeping for 10 seconds...\n", getpid());
        sleep(10);
        system("ps -el | grep Z");
        wait(NULL);
        printf("Zombie cleared\n");
    }

    return 0;
}

/* 🧪 Run this way:
nano zombie.c
gcc zombie.c -o zombie
./zombie
In another terminal, during the 10-second sleep:
ps -el | grep Z
You’ll see a line like:
<defunct> */
