#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

// Author : Divya Meharwade
// Below code displays the pid of the current process
// And forks 9 processes as defined in the assignment.
// No parent process has more than 2 child processes.
// Initial 2 forks create 4 processes
// only 2 child processes enter the if section
// firts fork on line 23 - create 2 additional processes 
// resulting in 6 total processes.
// fork on line 24 is executed by all 4 process and hence
// 4 additional processes are created resulting in 10.
// 9 new child processes and 1 original parent process

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
