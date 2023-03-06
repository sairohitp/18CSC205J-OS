// For n fork() calls executed one after another

// Total process = ((2^n) - 1 child processes) + (1 parent process) = 2^n processes
// Total number of child processes created is [(2^n)-1]

// For 10 fork() calls, the answer will be 2^10–1 = 1023

#include <stdio.h>
#include <unistd.h>

int main() {
    int n = 10;
    int count = 0;

    for (int i = 0; i < n; i++) { 
        fork();
        count += 1;
    }

    printf("%d", count);

    return 0;
}