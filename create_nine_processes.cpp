#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() 
{
    printf("original Process is %d\n", getpid()); // its Parent is not considered as per nine processes creation as per assignment requirement
    pid_t pid;
    
    pid = fork(); // creates 2 processes with 1 Child & 1 Parent
    pid = fork(); // creates 4 processes with 2 Child & 2 Parent

    // only the child processes should execute
    // hence only 2 Child processes enter the if section
    if (pid == 0) // if pid is 0, it indicates its a Child process
    {
        fork();  // total 6 processes with 2 Child & 2 Parent 
        fork();  // total 10 processes with 2 Child & 2 Parent 
    } 

    printf("Child --> %d | Parent --> %d\n", getpid(), getppid());

    while (wait(NULL) > 0) {} // wait for each Child process

    return 0;
}
