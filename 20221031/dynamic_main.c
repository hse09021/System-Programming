#include "kvs.h"
#include <dlfcn.h>

int main()
{
	void* handle;
	char* error;
	kvs_t* (*open)();
	int (*close)(kvs_t* kvs);
	int (*put)(kvs_t* kvs, const char* key, const char* value);
	char* (*get)(kvs_t* kvs, const char* key);
	int (*seek) (kvs_t* kvs);

	handle = dlopen("./libkvs.so", RTLD_LAZY);

	if(!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(-1);
	}

	open = dlsym(handle, "open");
	if((error = dlerror()) != NULL) {
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	close = dlsym(handle, "close");
	if((error = dlerror()) != NULL) {
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	put = dlsym(handle, "put");
	if((error = dlerror() != NULL)) {
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	get = dlsym(handle, "get");
	if((error = dlerror() != NULL)) {
		fprintf(stderr, "%s\n", error);
		exit(1);
		}
	seek = dlsym(handle, "seek");
	if((error = dlerror() != NULL)) {
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	// 1. create KVS
	kvs_t* kvs = open();

	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}

	// 2. put data 
	printf("Put operation ...\n");	
	// 1) file read
	FILE *fp = NULL;
	fp = fopen("student.dat", "r");

	if(fp == NULL) {
		printf("Failed to open file\n");
		return -1;
	}
	// 2) put data
	char key[100];
	char* value = (char*) malloc (sizeof(char)* 300);
	char* rvalue;

	while(!feof(fp)) {
		if(fscanf(fp, "%s %s\n", key, value) == 2) {
			if(put(kvs, key, value) < 0) {
				printf("Failed to put data\n");
				exit(-1);
			}
		}
	}
	printf("\n");
	fclose(fp);
#if 0 
	char key[100]; 
	char* value = (char*) malloc (sizeof(char)* 300);
	char* rvalue;

	strcpy(key, "Eunji");
	strcpy(value, "Seoul");

	if(put(kvs, key, value) < 0){
		printf("Failed to put data\n");
		exit(-1);
	}

#endif


	// 3. get for test 
	
	// 1) file read
	FILE *fp0 = fopen("student.dat", "r");

	if(fp0 == NULL) {
		printf("Failed to open file\n");
		return -1;
	}

	printf("Get operation ...\n");
	// 2) get & compare return value with original vallue 
	while(!feof(fp0)) {
		if(fscanf(fp0, "%s %s\n", key, value) == 2) {
			if(!(rvalue = get(kvs, key))) {
				printf("Failed to get data\n");
				exit(-1);
			}
			printf("get: %s, %s\n", key, rvalue);
		}
	}
	printf("\n");
	fclose(fp0);

#if 0
	if(!(rvalue = get(kvs, key))){
		printf("Failed to get data\n");
		exit(-1);
	}

	printf("get: %s, %s\n", key, rvalue);
#endif

	// 4. print all items 
	printf("Seek operation ...\n");
	
	int nitems = seek(kvs);
#if 0
	int nitems = seek(kvs);
	printf("%d items are found\n", nitems);


	// 5. close 
	close(kvs);
#endif
	close(kvs);
	return 0;
}
