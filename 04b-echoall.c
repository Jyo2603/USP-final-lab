// ✅ echoall.c (prints all arguments)

#include <stdio.h>

int main(int c, char *v[]) {
    for (int i = 0; i < c; i++)
        printf("argv[%d] = %s\n", i, v[i]);
    return 0;
}

// ✅ inter.c (creates child to run interpreter)

#include <unistd.h>
#include <sys/wait.h>

int main() {
    if (fork() == 0)
        execl("./textinterpreter", "x", "arg1", "arg2", NULL);
    else
        wait(NULL);
    return 0;
}

// ✅ textinterpreter (shell script to run echoall)

#!/bin/bash
./echoall my2 "$@"

/* 🔧 Instructions to Run
chmod +x textinterpreter       # Make the script executable
gcc echoall.c -o echoall       # Compile echoall
gcc inter.c -o inter           # Compile inter
./inter                        # Run the program

🧪 Output Example
argv[0] = ./echoall
argv[1] = my2
argv[2] = arg1
argv[3] = arg2 */
