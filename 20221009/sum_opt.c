#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<limits.h>

#define MAX_NUM 100000000
//#define MAX_NUM 1000000000
//#define MAX_NUM INT_MAX
//#define MAX_NUM 100000

struct vec {
	int len;
	int *data;
};
typedef struct vec vec_t;

int get_vec_element(vec_t* v, int idx, int *val) {
	assert(v);

	if(idx >= v->len) {
		return 0;
	}

	*val = v->data[idx];
	return 1;
}

int vec_length(vec_t* v) {
	assert(v);
	return v->len;
}

void combine(vec_t* v, int *dest) {
	assert(dest);
	*dest = 0;
	int length = vec_length(v);
	int limit = length - 1;
	int *d = v->data;
	int i = 0;

	for (; i < limit; i++){
		*dest += (d[i] + d[i + 1]); 
	}
	
	for (; i < length; i++) {
		*dest += d[i];
	}
}

void init(vec_t* v) {
	assert(v);
	v->len = MAX_NUM;
	int limit = MAX_NUM - 1;
	v->data = (int*) malloc(sizeof(int) * MAX_NUM);
	int *d = v->data;
	int i = 0;

	// init
	for (; i < limit; i++) {
		d[i] = i;
		d[i + 1] = ++i;
	}
	for (; i < MAX_NUM; i++) {
		d[i] = i;
	}
}

int main() {
	printf("This is the naive version .. \n");

	vec_t info; 
	int result; 
	// init 
	init(&info);

	// combine 
	combine(&info, &result);
	//printf("combined val = %d\n", result);

	return 0;
}
