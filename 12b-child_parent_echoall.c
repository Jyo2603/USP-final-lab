// ✅ run.c (main code)

#include <unistd.h>
#include <sys/wait.h>

int main() {
    char *env[] = {"USER=myuser", "PATH=/custom", NULL};

    if (fork() == 0) {
        execle("./echoall", "echoall", "child_arg", NULL, env);  // Child: custom env
    } else {
        wait(NULL);
        execlp("./echoall", "echoall", "parent_arg", NULL);      // Parent: default env
    }

    return 0;
}

// ✅ echoall.c (prints args and env)

#include <stdio.h>

int main(int argc, char *argv[], char *env[]) {
    for (int i = 0; argv[i]; i++) printf("argv[%d]=%s\n", i, argv[i]);
    for (int i = 0; env[i]; i++)  printf("env[%d]=%s\n", i, env[i]);
    return 0;
}

/* 🧪 How to Compile & Run:
gcc echoall.c -o echoall
gcc run.c -o run
./run

✅ Output Sample:
argv[0]=echoall
argv[1]=child_arg
env[0]=USER=myuser
env[1]=PATH=/custom
... */
