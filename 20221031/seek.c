#include "kvs.h"

int seek(kvs_t* kvs) {
	node_t* cur = kvs -> db -> next;
	while(cur) {
		printf("(%s, %s)\n", cur -> key, cur -> value);
		cur = cur -> next;
	}
	return kvs -> items;
}
