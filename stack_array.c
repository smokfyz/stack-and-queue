#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SIZE 30

typedef int type;

struct stack_t {
	unsigned capacity;
	unsigned top;
	type arr[SIZE];
};


typedef struct stack_t Stack;


Stack* initStack() {
	Stack* stack = (Stack*)calloc(1, sizeof(Stack));
	stack->capacity = SIZE;
	return stack;
}


void push(Stack* stack, type value) {
	stack->arr[stack->top] = value;
	stack->top == stack->capacity-1 ? stack->top = 0 : stack->top++;
}


type pop(Stack* stack) {
	type value;
	value = stack->arr[stack->top-1];
    stack->top--;	
	return value;
}


type top(Stack* stack) {
	return stack->arr[stack->top-1];
}


unsigned size(Stack* stack) {
	return stack->top;
}


bool isEmpty(Stack* stack) {
	return !(bool)stack->top;
}

int main() {
	int num;
	Stack* stack = initStack();
	while(scanf("%d", &num)) {
		push(stack, num);
	}
	while(!isEmpty(stack)) {
		printf("[TOP]%d\n", top(stack));
		printf("[POP]%d\n", pop(stack));
		printf("[SIZE]%d\n\n", size(stack));
	}

	return 0;
}
