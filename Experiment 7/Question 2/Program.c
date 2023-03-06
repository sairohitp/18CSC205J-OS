#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd[2];
    pid_t pid;
    
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    
    pid = fork();
    
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // child process
        close(fd[0]); // close read end of pipe
        
        // redirect stdout to write end of pipe
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]); // close write end of pipe
        
        // execute "ls -l" command
        execlp("ls", "ls", "-l", NULL);
        perror("execlp"); // this line is reached only if execlp fails
        exit(EXIT_FAILURE);
    } else { // parent process
        close(fd[1]); // close write end of pipe
        
        // redirect stdin to read end of pipe
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]); // close read end of pipe
        
        // execute "wc -l" command
        execlp("wc", "wc", "-l", NULL);
        perror("execlp"); // this line is reached only if execlp fails
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
