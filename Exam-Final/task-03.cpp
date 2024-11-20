/**
 *    author:  tourist
 *    created: 2024.11.20 13:46:43
**/

#include <stdio.h>
#include <stdlib.h>

const int N = 15;

typedef struct Queue {
	int size;
	int elems[N];
} Queue;

void createQueue(Queue **L) {
	(*L) = (Queue*)malloc(sizeof (Queue));
	(*L)->size = 0;
}

int isEmpty(Queue *L) {
	return (L->size == 0);
}

int isFull(Queue *L) {
	return (L->size == N);
}

void enQueue(Queue **L, int x) {
	if (isFull(*L)) {
		printf("Hang doi day\n");
	} else {
		(*L)->elems[(*L)->size++] = x;
	}
}

void deQueue(Queue **L, int *x) {
	if (isEmpty(*L)) {
		printf("Hang doi rong\n");
	} else {
		*x = (*L)->elems[0];
		for (int i = 0; i < (*L)->size - 1; ++i) {
			(*L)->elems[i] = (*L)->elems[i + 1];
		}
		(*L)->size--;
	}
}

void input(Queue **L) {
	int n, x;
	createQueue(L);

	printf("Nhap so luong hang doi: ");
	scanf("%d", &n);

	printf("Nhap gia tri cac phan tu trong hang doi: ");
	for (int i = 0; i < n; ++i) {
		printf("Nhap x: ");
		scanf("%d", &x);
		enQueue(L, x);
	}
}

void display(Queue *L) {
	if (isEmpty(L)) {
		printf("Hang doi rong\n");
	} else {
		for (int i = 0; i < L->size; ++i) {
			printf("%d ", L->elems[i]);
		}
	}
}

int locate(Queue *L, int x) {
	int pos = 0;
	while ((L->elems[pos] != x) && (pos < L->size)) {
		++pos;
	}

	if (pos == (L->size)) return -1;
	return pos + 1;
}	

void insertAtPosition(Queue **L, int k, int x) {
	if (isFull(*L)) {
		printf("Hang doi day, khong the chen\n");
		return;
	}

	if (k < 1 || k > (*L)->size + 1) {
		printf("Vi tri chen khong hop le\n");
		return;
	}

	for (int i = (*L)->size; i >= k; --i) {
		(*L)->elems[i] = (*L)->elems[i - 1];
	}

	(*L)->elems[k - 1] = x;
	(*L)->size++;
}

void deQueueAtPosition(Queue **L, int k, int *x) {
	if (isEmpty(*L)) {
		printf("Hang doi rong\n");
		return;
	}

	if (k < 1 || k > (*L)->size) {
		printf("Vi tri khong hop le!");
		return;
	}

	*x = (*L)->elems[k - 1];
	for (int i = k - 1; i < (*L)->size - 1; ++i) {
		(*L)->elems[i] = (*L)->elems[i + 1];
	}

	(*L)->size--;
}

int main() {
	Queue *L;
	int x;
	input(&L);

	printf("Cac phan tu trong hang doi\n");
	display(L);

	printf("Nhap phan tu can chen x= ");
	scanf("%d", &x);
	enQueue(&L, x);

	printf("Cac phan tu trong hang doi sau khi chen\n");
	display(L);

	printf("Cac phan tu trong hang doi sau khi xoa\n");
	deQueue(&L, &x);
	display(L);

	printf("Nhap phan tu can tim x= ");
	scanf("%d", &x);

	if (locate(L, x) == 0) {
		printf("Khong ton tai trong hang doi\n");
	} else {
		printf("Vi tri so: %d\n", locate(L, x));
	}

	printf("Nhap vi tri k de lay phan tu ra khoi hang doi= ");
	int k;
	scanf("%d", &k);

	deQueueAtPosition(&L, k, &x);
	printf("Phan tu lay ra tu vi tri k= %d\n", x);

	printf("Cac phan tu trong hang doi sau khi lay phan tu ra\n");
	display(L);

	free(L);

	return 0;
}