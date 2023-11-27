#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Usage: %s <exec command> [arg0, arg1, arg2, ...]\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork error");
        return 1;
    }

    if (pid == 0) {

        execvp(argv[1], argv + 1);
        perror("execvp error");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, NULL, 0);
        return 0;
    }
}
