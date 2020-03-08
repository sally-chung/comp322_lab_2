
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // tube
    /* 1) The program allocates a pipe 
        (pipe(2)) */

    /* 2) The program forks two children */

    /* 3) The parent process prints the PID of both children on stderr 
          (fprintf) */

    /* 4) The parent process closes access to the pipe and the child processes 
          wires the pipe to allow for inter-process communication 
          (dup(2)) 
          - via the stdout-stdin approach
            (close(2)) */

    /* 5) The first process executes the first command,
       and the second process executes the second command
          - for the first iteration, keep it simple 
            -- i.e. the child has no command line args
          - enhance your program to allow for an arbitrary num of command line args */

    /* 6) the program prints the return value of the first child and then the second child on stderr */

}