#include <sys/types.h>
#include <sys/times.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int status;
    pid_t childPID; // creating a child process
    childPID = 0;
    pid_t parentPID;
    pid_t selfPID;


    // launch
    /* 1) the program forks a child process */
    childPID = fork();
    
    selfPID = getpid();
    parentPID = getppid(); 

    /* 2) the parent process prints the PID of the child on stderr */
    fprintf(stderr, "\n$$ = %d", getpid);

    /* 3) the child process executes the supplied command (execve)
        - the child needs to prepare the new argv structure */

    /* 4) the parent prints the return value of the child on stderr (waitpid) */
    
    waitpid(childPID, &status, 0); 
    fprintf(stderr, "\n$? = &d", WIFEXITED(status));

    // tube
    /* 1) The program allocates a pipe */

    /* 2) The program forks two children */

    /* 3) The parent process prints the PID of both children on stderr (fprintf) */

    /* 4) The parent process closes access to the pipe and the child processes wires the pipe to allow for inter-process communication */
}