/**
 *    author:  tourist
 *    created: 2024.11.20 14:10:11
**/

#include <stdio.h>
#include <stdlib.h>

const int N = 105;

typedef struct Node {
	int data;
	Node *next;
} Node;

typedef struct Queue {
	int size;
	Node *front;
	Node *rear;
} Queue;

Node* makeNode(int x) {
	Node *newNode = (Node*)malloc(sizeof (Node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void init(Queue **q) {
	(*q) = (Queue*)malloc(sizeof (Queue));
	(*q)->size = 0;
	(*q)->front = NULL;
	(*q)->rear = NULL;
}

int isEmpty(Queue *q) {
	return q->size == 0;
}

void push(Queue **q, int x) {
	Node *newNode = makeNode(x);

	if (isEmpty(*q)) {
		(*q)->front = (*q)->rear = newNode;
	} else {
		(*q)->rear->next = newNode;
		(*q)->rear = newNode;
	}

	(*q)->size++;
}

int pop(Queue **q) {
	if (isEmpty(*q)) return -1;
	
	int x = (*q)->front->data;
	Node *del = (*q)->front;

	if ((*q)->size == 1) {
		free(del);
		init(q);
	} else {
		(*q)->front = (*q)->front->next;
		free(del);
	}

	(*q)->size--;
	return x;
}

void input(Queue **q) {
	int n, x;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		printf("Nhap phan tu %d: ", i + 1);
		scanf("%d", &x);
		push(q, x);
	}
}

void display(Queue *q) {
	if (isEmpty(q)) return;
	Node *cur = q->front;

	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}

	printf("\n");
}

void insertAtPosition(Queue **q, int k, int x) {
	if (k < 1 || k > (*q)->size + 1) {
		printf("Vi tri khong hop le\n");
		return;
	}

	Node *newNode = makeNode(x);
	if (k == 1) {
		newNode->next = (*q)->front;
		(*q)->front = newNode;

		if ((*q)->size == 0) {
			(*q)->rear = newNode;
		}
	} else {
		Node *cur = (*q)->front;
		for (int i = 1; i < k - 1; ++i) {
			cur = cur->next;
		}

		newNode->next = cur->next;
		cur->next = newNode;

		if (newNode->next == NULL) {
			(*q)->rear = newNode;
		}
	}

	(*q)->size++;
}

int main() {

	return 0;
}