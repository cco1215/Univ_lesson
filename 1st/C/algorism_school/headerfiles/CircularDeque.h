//CircularDequeue.h
#pragma once
#include "CircularQueue.h"


void init_deque() {
	init_queue();
}
void add_rear(Element val) {
	enqueue(val);
}
Element delete_front() {
	return dequeue();
}
Element get_front() {
	return peek();
}
void add_front(Element val) {
	if (is_full()) {
		error("오버플로우");
	}
	front = (front - 1 + MAX_SIZE) % MAX_SIZE;
	data[front] = val;
}
Element delete_rear() {
	if (is_empty()) {
		error("언더플로우");
	}
	int prev = rear;
	rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
	return data[prev];
}

Element get_rear() {
	if (is_empty()) {
		error("언더플로우");
	}
	return data[(rear + MAX_SIZE) % MAX_SIZE];
}