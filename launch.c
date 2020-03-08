// #include <sys/types.h>
// #include <sys/times.h>
// #include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    
    int status;
    pid_t childPID; // creating a child process
    childPID = 0;
    pid_t parentPID;
    pid_t selfPID;


    // char* env_arg[] = {"PATH=/bin/bin", NULL};

    // char* inputArgv[] = {"launch", "/bin/bin/ls", "-l", "-a", NULL};
    // char* argv[] = {"launch", "ls"}

    // splitting argv[1] by '/' 
    int counter = 0;
    char* env_arg[1000];
    char* c = "/";

    char* token = strtok(argv[1], "/");
    printf("argc:%d\n", argc);
    env_arg[0] = "PATH=";
    while(token!=NULL){
        printf("%s\n", token); 
        char tempString[100];
        printf("envarg: %s\n", env_arg[0]);
        strcpy(tempString, env_arg[0]);
        printf("tempstring: %s\n", tempString);
        strcat(tempString, c);
        strcat(tempString, token);
        printf("%s\n", env_arg[0]);
        token = strtok(NULL, "/");
        if(token=="ls") {
            env_arg[0] = tempString;
        }
    };

//    int pos = 0;
//    printf("/%s", env_arg[0]);

    

    // given argv[1] /bin/bin/ls, populate env_arg PATH=/foldername/foldername/ls
    // en


    // /bin/bin/ls
    

    // launch
    /* 1) the program forks a child process */
    childPID = fork();
    
    selfPID = getpid();
    parentPID = getppid(); 

    /* 2) the parent process prints the PID of the child on stderr */
    if (childPID > 0) {
        fprintf(stderr, "\n$$ = %d", childPID);


    /* 3) the child process executes the supplied command (execve)
        - the child needs to prepare the new argv structure */

    /* 4) the parent prints the return value of the child on stderr (waitpid) */
        
        waitpid(childPID, &status, 0); 
        fprintf(stderr, "\n$? = %d\n", WIFEXITED(status));
    }

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