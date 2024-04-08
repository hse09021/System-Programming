#include "kvs.h"

int put(kvs_t* kvs, const char* key, const char* value)
{
	printf("put: %s, %s\n", key, value);
	
	node_t* cur = kvs -> db;

	while(1) {
		if(kvs -> items == 0) {
			cur = (node_t*) malloc(sizeof(node_t));
			strcpy(cur -> key, key);
			cur -> value = value;
			cur -> next = NULL;
			kvs -> db = cur;

			break;
		}
		else if(cur -> next == NULL) {
			cur -> next = (node_t*) malloc(sizeof(node_t));
			strcpy(cur -> next -> key, key);
			cur -> next -> value = value;
			cur -> next -> next = NULL;

			break;
		}

		else {
			cur = cur -> next;
		}
	}

	kvs -> items++;

	return 0;
}
