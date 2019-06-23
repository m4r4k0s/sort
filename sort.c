#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>

#include "deque.h"
#include "sort.h"

deq merge(deq *left, deq *right) {
	deq merge_result;
	create_deq(&merge_result);
	deq final;
	create_deq(&final);
	while (!empty_check(left) || !empty_check(right)) {
		data_type l_elem, r_elem;
		if (empty_check(left)) {
			if (!empty_check(right))
				while (!empty_check(right)) {
					r_elem = pop_back(right);
					push_front(&final, r_elem);
				}
			continue;
		}
		if (empty_check(right)) {
			if (!empty_check(left))
				while (!empty_check(left)) {
					l_elem = pop_back(left);
					push_front(&final, l_elem);
				}
			continue;
		}
		l_elem = pop_back(left);
		r_elem = pop_back(right);
		if (l_elem.key < r_elem.key) {
			push_front(&final, l_elem);
			push_front(right, r_elem);
		}
		else {
			push_front(&final, r_elem);
			push_front(left, l_elem);
		}
	}
	while (!empty_check(&final)) {
		data_type replace = pop_back(&final);
		push_front(&merge_result, replace);
	}
	return merge_result;
}

void sort(deq *s){
        if (s -> sz <= 1) return;
        int mid = s -> sz / 2;
        deq help;
        create_deq(&help);
        for (int i = 0; i < mid; ++i){
				data_type replace = pop_back(s);
                push_front(&help, replace);
        }
        deq first;
        create_deq(&first);
        while (!empty_check(&help)){
                data_type replace = pop_back(&help);
				push_front(&first, replace);
        }
        deq second;
        create_deq(&second);
        while (!empty_check(s)){
                data_type replace = pop_back(s);
				push_front(&help, replace);
        }
		while (!empty_check(&help)) {
			data_type replace = pop_back(&help);
			push_front(&second, replace);
		}
        sort(&first);
        sort(&second);
        *s = merge(&first, &second);
} 
