#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>

#include "deque.h"
#include "sort.h"


void menu(){
	printf("1) Push back ");
	printf("2) Pop back ");
	printf("3) Push front \n");
	printf("4) Pop front ");
	printf("5) Empty check ");
	printf("6) Get size \n");
	printf("7) Sort ");
	printf("8) Print deque ");
	printf("0) End\n");
}

int main(int argc, char const *argv[]){
	deq d;	
	create_deq(&d);
	printf("Menu:\n");
	menu();
	int comand;
	while (scanf("%d", &comand)){
		if (comand == 1){
			data_type input;
			printf("Enter key:\n");
			scanf("%d",&input.key);
			printf("Enter value:\n");
			scanf("%d",&input.value);
			push_back(&d, input);
		}
		if (comand == 2){	
			pop_back(&d);
		}
		if (comand == 3){
			data_type input;
			printf("Enter key:\n");
			scanf("%d",&input.key);
			printf("Enter value:\n");
			scanf("%d",&input.value);
			push_front(&d, input);
		}
		if (comand == 4){
			pop_front(&d);
		}
		if (comand == 5){
			if (empty_check(&d)){
				printf("Empty!\n");
			}else{
				printf("Not empty!\n");
			}
		}
		if (comand == 6){
			int sz;
			sz = deq_size(&d);
			printf("Size is: %d\n",sz);
		}
		if (comand == 7){
			sort(&d); 
		}
		
		if (comand == 8){
			print_deque(&d);
		}
		if (comand == 0) break;
		menu();
	}
	return 0;
} 
