// ✅ main.c

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        execl("./p1", "p1", "example.txt", NULL);
    } else {
        printf("Parent PID: %d\n", getpid());
        wait(NULL);
        printf("Child (PID %d) exited.\n", pid);
    }
}

// ✅ p1.c

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (access(argv[1], F_OK) == 0)
        puts("File exists.");
    else
        puts("File doesn't exist.");
    return 0;
}

/*  🔧 Compile & Run
echo "hi" > example.txt
gcc p1.c -o p1
gcc main.c -o main
./main
You should now see:
Parent PID: 5023
Child PID: 5024
File exists.
Child (PID 5024) exited. */
