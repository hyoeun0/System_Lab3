#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	int i;
	int num;

	if (argc < 1) {
		printf("Hi!\n");
	} else {
		num = atoi(argv[1]);

		for (i = 0; i < num; i++) {
			pid_t child_pid = fork();
			if (child_pid == 0) {
				printf("Hello\n");
				exit(0);
			}
		}
		for (i = 0; i < num; i++) {
			wait(NULL);
		}
	}
	return 0;
}
