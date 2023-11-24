# NineProcessesCreation_OS_Assignment - COEN 283 HomeWork 1

This C code demonstrates the creation of multiple child processes using the `fork()` system call in a Unix-like environment. Here's a breakdown of how the code works:

1. **Header Files**: Includes necessary header files like `stdio.h`, `sys/wait.h`, and `unistd.h`.

2. **Main Function**: 
    - Prints the PID of the original process (parent process).
    - Declares a variable `pid` of type `pid_t`.
    - Performs two `fork()` calls consecutively:
        - The first `fork()` creates two processes, resulting in one parent and one child process.
        - The second `fork()` is immediately after the first one, resulting in each of the two processes creating an additional child process. This leads to a total of four processes (two parent processes and two child processes).
    - Enters an `if` block that checks if the process ID (`pid`) is equal to `0` (indicating it's a child process):
        - Inside this block, two more `fork()` calls are executed, resulting in the two child processes from the previous step creating additional child processes. This leads to a total of ten processes (two initial parents + two initial children + six additional child processes).

3. **Output**: Prints the PID of each process (`getpid()`) and its parent's PID (`getppid()`). It should display information for all ten processes created during the execution.

4. **Wait for Child Processes**: Uses `wait(NULL)` in a `while` loop to wait for each child process to terminate before the program itself terminates (`wait()` returns `-1` when no child processes are left to wait for).

In summary, this code uses nested `fork()` calls to generate multiple child processes, controlling the process count to ensure no parent process generates more than two child processes, as specified in the assignment. The code then displays the PIDs of all created processes and their parent processes.
