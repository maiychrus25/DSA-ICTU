/**
 *    author:  tourist
 *    created: 2024.11.20 14:30:35
**/

#include <stdio.h>
#include <stdlib.h>

const int N = 15;

typedef struct stack {
	int top;
	int data[N];
} stack;

void init(stack *st) {
	st->top = -1;
}

int isEmpty(stack *st) {
	return st->top == -1;
}

int isFull(stack *st) {
	return st->top == N - 1;
}

void push(stack *st, int x) {
	if (isFull(st)) {
		printf("Ngan xep day, khong the them phan tu\n");
		return;
	}
	st->data[++st->top] = x;
}

int pop(stack *st) {
	if (isEmpty(st)) {
		printf("Ngan xep rong, khong the xoa phan tu\n");
		return -1;
	}
	return st->data[st->top--];
}

void input(stack *st) {
	int n, x;
	printf("Nhap so luong phan tu: ");
	scanf ("%d", &n);

	for (int i = 0; i < n; ++i) {
		printf("Nhap phan tu thu %d: ", i + 1);	
		scanf("%d", &x);
		push(st, x);
	}
}

void display(stack *st) {
	if (isEmpty(st)) {
		printf("Ngan xep rong\n");
		return;
	}

	for (int i = 0; i <= st->top; ++i) {
		printf("%d ", st->data[i]);
	}

	printf("\n");
}

void decimalToBinary(int n) {
	stack st;
	init(&st);

	while (n > 0) {
		push(&st, n % 2);
		n /= 2;
	}

	printf("So nhi phan: ");
	while (!isEmpty(&st)) {
		printf("%d", pop(&st));
	}

	printf("\n");
}

int main() {
	stack st;
	init(&st);
	input(&st);

	display(&st);
	decimalToBinary(2);

	return 0;
}