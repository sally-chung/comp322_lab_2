#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // tube

    int status;
    int pipefd[2];
    pid_t child1PID; // creating a child process
    child1PID = 0;
    pid_t child2PID;
    child2PID = 0;
    /* 1) The program allocates a pipe 
        (pipe(2)) */
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    /* 2) The program forks two children */
    child1PID = fork();
    if(child1PID == 0 ) {
        fprintf(stderr, "%s: $$ = %d\n", argv[1], child1PID);
        // child1code
    } else {
        child2PID = fork();
        if (child2PID == 0) {
            fprintf(stderr, "%s: $$ = %d\n", argv[3], child2PID);
            // child2code
        } else { 
            // parent code
            
            /* 3) The parent process prints the PID of both children on stderr 
            (fprintf) */
            waitpid(child1PID, &status, 0);
            fprintf(stderr, "%s: c1 $? = %d\n", argv[1], WEXITSTATUS(status));
            waitpid(child2PID, &status, 0); 
            fprintf(stderr, "%s: c2 $? = %d\n", argv[3], WEXITSTATUS(status));
            /* 4) The parent process closes access to the pipe and the child processes 
             wires the pipe to allow for inter-process communication 
            (dup(2)) 
            - via the stdout-stdin approach
            (close(2)) */
            close(pipefd[1]);
        }
    }




    /* 5) The first process executes the first command,
       and the second process executes the second command
          - for the first iteration, keep it simple 
            -- i.e. the child has no command line args
          - enhance your program to allow for an arbitrary num of command line args */

    /* 6) the program prints the return value of the first child and then the second child on stderr */

}