#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();   // create child process

    if (pid < 0) {
        // fork failed
        perror("fork failed");
        return 1;
    } 
    else if (pid == 0) {
        // child process
        printf("Child process running ls command\n");
        execlp("ls", "ls", NULL);

        // if exec fails
        perror("exec failed");
        return 1;
    } 
    else {
        // parent process
        wait(NULL); // wait for child to finish
        printf("Parent process finished\n");
    }

    return 0;
}
