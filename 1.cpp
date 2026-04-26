/*
Question 1-Process
Write a C program that creates a child process using fork(). Print:
    Parent PID
    Child PID
    Parent Process ID (PPID) of child
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){
    pid_t pid = fork();

    if(pid < 0){
        perror("Fork failed");
        return 1;
    }
    
    if(pid == 0){
        printf("Child PID: %d\n",getpid());
        printf("Parent Process ID (PPID) of child: %d\n", getppid());
    }

    else{
        printf("Parent PID: %d\n", getpid());
        printf("Child PID (from parent): %d\n", pid);

        wait(NULL);
    }

    return 0;
}