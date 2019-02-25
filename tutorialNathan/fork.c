#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("This");
    pid_t child_pid = fork();
    // The child process
    if (child_pid == 0) {
        pid_t child2_pid = fork();
        printf("### Child ###\nCurrent PID: %d and Child PID: %d\n",
               getpid(), child2_pid);
    } else {
        pid_t child2_pid = fork();
        printf("### Parent ###\nCurrent PID: %d and Child PID: %d\n",
               getpid(), child_pid);
    }
 
    return 0;
}