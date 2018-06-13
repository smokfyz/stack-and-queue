#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int type;

struct queue_t {
	struct node_t* begin;
	struct node_t* end;
};

struct node_t {
	type value;
	struct node_t* next;
	struct node_t* prev;
};

typedef struct queue_t Queue;
typedef struct node_t Node;


Queue* initQueue() {
	Queue* queue = (Queue*)calloc(1, sizeof(Queue));
	return queue;
}


void enqueue(Queue* queue, type value) {
	Node* new_element = (Node*)calloc(1, sizeof(Node));
	new_element->next = queue->begin;
	if(queue->begin) queue->begin->prev = new_element;
	if(!queue->end) queue->end = new_element;
	new_element->value = value;
	queue->begin = new_element;
}


type dequeue(Queue* queue) {
	type value;
	Node* end_el = queue->end;
	queue->end = end_el->prev;
	if(end_el->prev) end_el->prev->next = NULL;
	else queue->begin = NULL;
	value = end_el->value;
	free(end_el);
	return value;
}

bool isEmpty(Queue* queue) {
	return !(bool)queue->begin;
}

int main() {
	int num;
	Queue* queue = initQueue();
	while(scanf("%d", &num)) enqueue(queue, num);
	while(!isEmpty(queue)) {
		printf("[DEQ]%d\n", dequeue(queue));
	}

	return 0;
}
