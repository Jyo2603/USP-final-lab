#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void h(int s) {
    puts("Ctrl+C pressed - Caught SIGINT");
    signal(SIGINT, SIG_DFL);
}

int main() {
    struct sigaction sa = {.sa_handler = h};
    sigaction(SIGINT, &sa, 0);

    while (1) {
        puts("Press Ctrl+C...");
        pause();
    }
}
