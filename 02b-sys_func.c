#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int my_sys(const char *cmd) {
    int s, pid = fork();
    if (!pid) execl("/bin/sh", "sh", "-c", cmd, 0);
    wait(&s);
    return WEXITSTATUS(s);
}

int main() {
    printf("Exit: %d\n", my_sys("ls -li"));
}
