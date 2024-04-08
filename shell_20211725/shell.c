#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	pid_t pid;
	pid = fork();
	int stat;
	if (pid > 0) {
		printf("Processing ...\n");
		wait(&stat);
		printf("completed.\n");
	}
	else { 
		for (int i = 1; i < argc; i++) {
			if (execvp(argv[i], &argv[i]) == -1) {
				printf("No such file or directory\n");
			}
		}
	}

	return 0;
}

