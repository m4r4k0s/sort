#ifndef _Deque_

#define __Deque__

#include <stdbool.h>

typedef struct{
	int key;
	int value;
}data_type;

typedef struct Udt
{
	data_type value[7];
	int sz;
	int head;
	int tail;
	int size;
}deq;

void create_deq(deq *); 
int deq_size(const deq *); 
void push_back(deq *, data_type element); 
void push_front(deq *, data_type element); 
data_type pop_back(deq *); 
data_type pop_front(deq *); 
bool empty_check(deq *); 
void print_deque(deq *); 


#endif 
