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
    // char* env_arg[] = {"PATH=/bin/bin", NULL};

    // char* inputArgv[] = {"launch", "/bin/bin/ls", "-l", "-a", NULL};
    // char* argv[] = {"launch", "ls", "-l", "-a", NULL;}

    // launch
    /* 1) the program forks a child process */
    childPID = fork();

    /* 2) the parent process prints the PID of the child on stderr */
    if (childPID > 0) {
        fprintf(stderr, "%s: $$ = %d\n", argv[1], childPID);
    }

    /* 3) the child process executes the supplied command (execve)
        - the child needs to prepare the new argv structure */
    if (childPID == 0){
            
        char* env_arg[30];
        char* outputArgv[30];
        char* c = "/";

        // splitting argv[1] by '/' 
        char* token = strtok(argv[1], "/");
        char* oldToken;
        char* tempString = (char*)malloc(100*sizeof(char));
        
        strcpy(tempString, "PATH=");
        
        while(token != NULL){
            oldToken = token;
            token = strtok(NULL, "/");
            if(token!=NULL) {
                strcat(tempString, c);
                strcat(tempString, oldToken);
            }
            else { 
                outputArgv[0] = (char*)malloc(100*sizeof(char));
                strcpy(outputArgv[0], oldToken);
            }
        };

    // given argv[1] /bin/bin/ls, populate env_arg PATH=/foldername/foldername/ls and following args

        for(int i = 2; i < argc; i++) {
            outputArgv[i-1] = argv[i];
        }
        outputArgv[argc-1] = NULL;

/*        for(int i = 0; i < argc-1; i++) {
            printf("outputArgv[%d]: %s\n", i, outputArgv[i]);
        } */
        
        env_arg[0] = (char*)malloc(100*sizeof(char));
        strcpy(env_arg[0], tempString);
        env_arg[1] = NULL;

        execve(outputArgv[0], outputArgv, env_arg);

        perror("Execve failed");
        free(tempString);
        free(env_arg[0]);
        free(outputArgv[0]);
        exit(EXIT_FAILURE);
    }    

    /* 4) the parent prints the return value of the child on stderr (waitpid) */
    if(childPID > 0) {   
        waitpid(childPID, &status, 0); 
        fprintf(stderr, "%s: $? = %d\n", argv[1], WEXITSTATUS(status));
    }


}