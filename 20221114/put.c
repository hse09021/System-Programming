#include "kvs.h"

int put(kvs_t* kvs, const char* key, const char* value)
{
	printf("put: %s, %s\n", key, value);
	
	node_t* new_node = (node_t*) malloc(sizeof(node_t));
	if(!new_node) {
		return -1;
	}
	new_node -> value = (char*) malloc(sizeof(value));
	if(!new_node) {
		return -1;
	}
	strcpy(new_node -> key, key);
	strcpy(new_node -> value, value);
	node_t* cur = kvs -> db;

	while(cur -> next) {
		int cmp = strcmp(cur -> next -> key, key);
		if(cmp > 0) {
			new_node -> next = cur -> next;
			cur -> next = new_node;
			kvs -> items++;
			
			return 0;
		}
		else if(!cmp) {
			free(new_node);
			free(cur -> next -> value);
			cur -> next -> value = (char*) malloc(sizeof(value));
			if(!cur -> next -> value) {
				return -1;
			}
			strcpy(cur -> next -> value, value);
			
			return 0;
		}
		cur = cur -> next;
	}
	cur -> next = new_node;
	kvs -> items++;

	return 0;
}
