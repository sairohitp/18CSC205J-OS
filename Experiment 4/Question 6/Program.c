// Write a program to print the Child process ID and Parent process ID in both Child and Parent processes

#include <stdio.h>
#include <unistd.h>

int main()
{
  int pid;

   pid = fork();

   if(pid !=0 ) { // entry to child is true
        printf("In Child process:\n");
        printf("Parent ID: %d\n" , getppid());
        printf("Child ID: %d\n" , pid);
   } else {
      printf("\nIn Parent process:\n");
      printf("Parent ID: %d\n", pid);
      printf("Child ID: %d\n", getpid());
   }

    return 0;
}