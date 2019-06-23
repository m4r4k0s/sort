#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>

#include "deque.h" 

void create_deq(deq *d){
	for (int i = 0; i < 7; ++i){
		d -> value[i].key = -10101010;
		d -> value[i].value = -10101010;
	}
	d -> tail = 0;
	d -> head = 0;
	d -> sz = 0;
	d -> size = 7;
}

void push_back(deq *d, data_type val){
	int size = d -> size;
	if (d -> head == d -> tail && d -> sz > 0){
		printf("Impossible\n");
		return;
	}
	d -> value[d -> tail] = val;
	d -> tail = (d -> tail + 1) % size;
	++d -> sz;
}

void push_front(deq *d, data_type val){
	int size = d -> size;
	if (d -> head == d -> tail && d -> sz > 0){
		printf("Impossible\n");
		return;
	}
	d -> head = (d -> head - 1 + size) % size;
	d -> value[d -> head] = val;
	++d -> sz;
}

data_type pop_back(deq *d){
	int size = d -> size;
	if (empty_check(d) && d -> sz == 0){
		printf("Impossible\n");
		data_type ret;
		ret.key = -10101010;
		ret.value = -10101010;
		return ret;
	}
	--d -> sz;
	d -> tail = (d -> tail - 1 + size) % size;
	return d -> value[d -> tail];
}

data_type pop_front(deq *d){
	int size = d -> size;
	if (empty_check(d) && d -> sz == 0){
		printf("Impossible\n");
		data_type ret;
		ret.key = -10101010;
		ret.value = -10101010;
		return ret;
	}
	--d -> sz;
	data_type ret = d -> value[d -> head];
	d -> head = (d -> head + 1) % size;
	return ret;
}

bool empty_check(deq *d){
	if (d -> head == d -> tail && d -> sz == 0) return true;
	else return false;
}

int deq_size(const deq *d){
	return d -> sz;
}

void print_deque(deq *d){
	int size = d -> size;
	int start = d -> tail;
	int end = d -> head;	
	int pos;
	if (empty_check(d) && d -> value[start].key == d -> value[end].key){
		printf("Empty!\n");
		return;
	}
	printf("  v\n");
	printf("%d: %d\n",d -> value[d -> head].key, d -> value[d -> head].value);
	pos = (d -> head + 1) % size;
	while (pos != d -> tail){
		printf("%d: %d\n",d -> value[pos].key, d -> value[pos].value);
		pos = (pos + 1) % size;
	}
	printf("  v\n");
}

