#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int type;

struct stack_t {
	struct node_t* begin;
};

struct node_t {
	type value;
	struct node_t* next;
};

typedef struct stack_t Stack;
typedef struct node_t Node;


Stack* initStack() {
	Stack* stack = (Stack*)calloc(1, sizeof(Stack));
	return stack;
}


void push(Stack* stack, type value) {
	Node* new_element = (Node*)calloc(1, sizeof(Node));
	new_element->next = stack->begin;
	new_element->value = value;
	stack->begin = new_element;

}


type pop(Stack* stack) {
	type value;
	Node* top = stack->begin;
	stack->begin = top->next;
	value = top->value;
	free(top);
	return value;
}


type top(Stack* stack) {
	return stack->begin->value;
}


unsigned size(Stack* stack) {
	unsigned size = 0;
	Node* current = stack->begin;

	while(current) {
		size++;
		current = current->next;
	}
	return size;
}


bool isEmpty(Stack* stack) {
	return !(bool)stack->begin;
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
