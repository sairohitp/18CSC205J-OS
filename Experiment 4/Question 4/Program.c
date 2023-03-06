// The child process calculates the sum of odd numbers
// the parent process calculate the sum of even numbers up to the number ‘n’. 
// Ensure the Parent process waits for the child process to finish.

#include <stdio.h>
#include <unistd.h>

int main() {

    int n, pid;
    int oddsum = 0, evensum = 0;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);

    pid = fork();

    // getting into child
    if (pid != 0) {
        for (int i = 0; i <= n; i++) {
            if (i%2 != 0) {
                oddsum += i;
            }
        }
        printf("Sum of odd numbers: %d\n", oddsum);
    } else { //get into parent 
        for (int i = 0; i <= n; i++) {
            if (i%2 == 0) {
                evensum += i;
            }
        }
        printf("Sum of even numbers: %d\n", evensum);
    }

    return 0;
}