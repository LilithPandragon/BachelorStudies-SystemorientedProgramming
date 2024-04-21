#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1;
    }

    int index = atoi(argv[1]);
    srand(index + getpid());
    int random_number = rand() % 101;

    printf("Child %d: Argument: %d, Zufallszahl: %d\n", getpid(), index, random_number);

    return random_number;
}
