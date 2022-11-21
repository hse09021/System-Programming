#include "kvs.h"

char* get(kvs_t* kvs, const char* key)
{
	node_t* cur = kvs -> db;

	while(1) {
		if(cur == NULL) {
			return NULL;
		}
		if(strcmp(cur -> key, key) == 0) {
			return cur -> value;
		}

		cur = cur -> next;
	}


	char* value = (char*)malloc(sizeof(char)*100);

	if(!value){
		printf("Failed to malloc\n");
		return NULL;
	}

	strcpy(value, "deadbeaf");
	return value;

}
