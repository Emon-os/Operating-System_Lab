/*
Create two child processes from one parent process and display the process tree.
*/


#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
    pid_t child1 = fork();

    if(child1 < 0){
        perror("Fork failed for child 1");
        return 1;
    }

    if(child1 == 0){
        // First child
        printf("Child 1 PID: %d | Parent PID: %d\n", getpid(), getppid());
        return 0;
    }

    pid_t child2 = fork();

    if(child2 < 0){
        perror("Fork failed for child 2");
        return 1;
    }

    if(child2 == 0){
        // Second Child 
        printf("Child 2 PID: %d | Parent PID: %d\n",getpid(), getppid());
        return 0;
    }

    printf("Parent PID: %d\n", getpid());
    printf("Process Tree:\n");
    printf("Parent (%d)\n",getpid());
    printf("|- Child 1 (%d)\n",child1);
    printf("|- Child 2 (%d)\n",child2);

    wait(NULL);
    wait(NULL);

    return 0;

}