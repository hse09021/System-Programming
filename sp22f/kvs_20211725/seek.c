#include "kvs.h"

int seek(kvs_t* kvs)
{
	node_t* cur = kvs -> db;
	kvs_t* ordered_kvs = (kvs_t*) malloc(sizeof(kvs_t));
	node_t* next_p;
	node_t* prev_p;

	if(ordered_kvs) {
		ordered_kvs -> items = 0;
	}

	while(1) {
		node_t* new_node = (node_t*) malloc(sizeof(node_t));
		strcpy(new_node -> key, cur -> key);
			
		if(ordered_kvs -> items == 0) {
			new_node -> value = cur -> value;
			new_node -> next = NULL;
			ordered_kvs -> db = new_node;
		}
		else {
			new_node -> value = cur -> value;
			next_p = ordered_kvs -> db;
			prev_p = NULL;

			while(next_p) {
				if(strcmp(next_p -> key, new_node -> key) > 0) {
					break;
				}
				prev_p = next_p;
				next_p = next_p -> next;
			}
			new_node -> next = next_p;

			if(prev_p) {
				prev_p -> next = new_node;
			}
			else {
				ordered_kvs -> db = new_node;
			}
		}
		ordered_kvs -> items++;
		if(cur -> next != NULL) {
			cur = cur -> next;
		}
		else {
			break;
		}
	}
	node_t* current = ordered_kvs -> db;

	int count = 0;
	while(count < ordered_kvs -> items) {
		printf("(%s, %s)\n", current -> key, current -> value);
		if(current -> next != NULL) {
			current = current -> next;
		}
		else {
			break;
		}
		count++;
	}	

	return ordered_kvs -> items;
}
