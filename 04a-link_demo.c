#include <stdio.h>
#include <unistd.h>

int main() {
    if (link("test1.txt", "hardlink.txt") == 0) {
        printf("Hard Link Created Successfully\n");
    } else {
        perror("Error creating Hard Link");
    }

    if (symlink("test.txt", "symlink.txt") == 0) {
        printf("Soft Link Created Successfully\n");
    } else {
        perror("Error creating Soft Link");
    }

    return 0;
}
