#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    printf("original process is %d\n", getpid());
    pid_t pid;
    
    pid = fork(); // creates 2 processes 1 child 1 parent
    pid = fork(); // creates 4 processes 2 child 2 parent

    // only the child processes should execute
    // hence only 2 child processes enter the if section
    if (pid == 0) {
        fork();  // total 6 processes, 2 child 2 parent 
        fork();  // total 10 processes, 2 child 2 parent 
    } 

    printf("I am %d and my parent is %d\n", getpid(), getppid());

    while (wait(NULL) > 0) {} // wait for each child process

    return 0;
}
