#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<readline/readline.h>


int main(int argc, char* argv[])
{
	pid_t pid;
	int status;
	char* cmdline;
	char* opt;
	while(1) {
        	cmdline = readline("$ ");
		opt = strtok(cmdline, " \n");

		if (!strcmp(opt, "quit")) {
        		break;
		}

		if ((pid = fork()) < 0) {
			printf("fork error\n");
			status = -1;
		}
		else if (!pid) {
			char* args[100];
			int i = 0;
		
			while(opt != NULL) {
				args[i] = (char*) malloc(sizeof(char) * 100);
				strcpy(args[i++], opt);
				opt = strtok(NULL, " \n");
			}
			
			char **command = &args[0];
			if (execvp(command[0], command) == -1) {
				printf("No such file or directory\n");
				exit(1);
			}
			
			exit(0);
		}
		else if (pid > 0) {
			int stat;
			pid_t wait_pid = waitpid(pid, &stat, 0);
		}
	}
		return 0;
}

