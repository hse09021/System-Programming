#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

#define BUFF_SIZE 16

int main(int argc, char* argv[]) {
	int ifd, ofd;
	char* buff;
	int nbytes;

	if(argc < 2) {
		fprintf(stdout, "No arguments\n");
		
		return 0;
	}
	else if(argc == 2) {
		// output to stdout file  
		ofd = STDOUT_FILENO;
	}
	else if(argc == 4 && !strcmp(argv[2], "into")) {
		// output to redirection file 
		if((ofd = open(argv[3], O_WRONLY | O_CREAT, 0644)) == -1) {
			fprintf(stderr, "Failed to open file\n");
			return 0;
		}
	}
	else {
		fprintf(stdout, "Wrong arguments\n");
		
		return 0;
	}

	// Open input file
	if((ifd = open(argv[1], O_RDONLY)) == -1) {
		fprintf(stderr, "Failed to open file\n");
		
		return 0;
	}

	// Allocate buffer 
	if(!(buff = (char*) malloc (sizeof(char) * BUFF_SIZE))){
		fprintf(stdout, "Failed to allocate memory\n");
		return 0;
	}

	// Copy files 
	while((nbytes = read(ifd, buff, sizeof(buff))) > 0) {
		write(ofd, buff, nbytes);
	}

	// Close files
	close(ifd);
	close(ofd);

	return 0;
}
