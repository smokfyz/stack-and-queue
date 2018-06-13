#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SIZE 30

typedef int type;

struct queue_t {
	unsigned capacity;
	unsigned begin;
	unsigned end;
	type arr[SIZE];
};

typedef struct queue_t Queue;


Queue* initQueue() {
	Queue* queue = (Queue*)calloc(1, sizeof(Queue));
	queue->capacity = SIZE;
	return queue;
}


void enqueue(Queue* queue, type value) {
	queue->arr[queue->end] = value;
	queue->end == queue->capacity-1 ? queue->end = 0 : queue->end++;
}


type dequeue(Queue* queue) {
	type value;
	value = queue->arr[queue->begin];
	queue->begin == queue->capacity-1 ? queue->begin = 0 : queue->begin++;
	return value;
}


bool isEmpty(Queue* queue) {
	return !(bool)(queue->begin - queue->end);
}


bool isFull(Queue* queue) {
	return !(bool)(queue->begin - queue->end);
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
