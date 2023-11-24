# NineProcessesCreation_OS_Assignment - COEN 283 HomeWork 1

## Name: Pavan Kumar Srinivasulu <br> Student ID: 07700005991 <br> Email: psrinivasulu@scu.edu

## Code Flow and Explanation <br>

This C code demonstrates the creation of 9 child processes using the `fork()` system call in a Unix-like environment. Here's a breakdown of how the code works:

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

### Running a C++ Program on Linux:

#### 1. Check for Compiler Installation:
- **Verify if `g++` is Installed**: Open a terminal and enter `g++ --version`. If installed, it will display the installed version. If not, you'll need to install the GNU Compiler Collection (GCC) to compile C++ code.

#### 2. Install GCC (if not installed):
- **Ubuntu/Debian**: Use `apt-get`:
  ```bash
  sudo apt-get update
  sudo apt-get install g++
  ```
- **CentOS/Fedora**: Use `yum`:
  ```bash
  sudo yum update
  sudo yum install gcc-c++
  ```

#### 3. Write Your C++ Code:
- Use a text editor (e.g., `nano`, `vim`, `gedit`, `code`) to write your C++ code. Save it with the `.cpp` extension. Here, `create_nine_processes.cpp`.

#### 4. Compile the Code:
- **Open Terminal**: Navigate to the directory containing your `create_nine_processes.cpp` file.
- **Compile using g++**:
  ```bash
  g++ -o output_file_name source_file_name.cpp
  ```
  Replace `output_file_name` with a desired name for the compiled executable and `source_file_name.cpp` with your C++ file name.
  
  here,<br>
  ```bash
  g++ -o output_hw1 create_nine_processes.cpp
  ```

#### 5. Run the Executable:
- **Execute the Compiled Program**:
  ```bash
  ./output_file_name
  ```
  Replace `output_file_name` with the name specified during compilation.

#### 6. Confirm Execution:
- You should now see the output of your C++ program in the terminal.

### Important Notes:
- Ensure the C++ file is saved with the `.cpp` extension.
- Make sure you have necessary permissions to read, write, and execute files in the directory.
- Resolve any errors or warnings that occur during compilation before running the executable.
- Debug any issues that arise during execution, considering the terminal output and any error messages.

