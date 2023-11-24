#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() 

{
    printf("original process is %d\n", getpid()); // its Parent is not considered as per nine processes creation as per assignment requirement
    pid_t pid;
    
    pid = fork(); // creates 2 processes with 1 child & 1 parent
    pid = fork(); // creates 4 processes with 2 child & 2 parent

    // only the child processes should execute
    // hence only 2 child processes enter the if section
    if (pid == 0) // if pid is 0, it indicates its a child process
    {
        fork();  // total 6 processes with 2 child & 2 parent 
        fork();  // total 10 processes with 2 child & 2 parent 
    } 

    printf("Child --> %d | Parent --> %d\n", getpid(), getppid());

    while (wait(NULL) > 0) {} // wait for each child process

    return 0;
}
