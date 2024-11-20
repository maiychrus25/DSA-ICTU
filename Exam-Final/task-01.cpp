/**
 *    author:  tourist
 *    created: 2024.11.20 12:52:34
**/

#include <stdio.h>
#include <stdlib.h>

const int N = 105;

typedef struct List {
	int size;
	int elems[N];
} List;

void init(List **list) {
	(*list) = (List*)malloc(sizeof (List));
	(*list)->size = 0;
}

int init_x() {
	int x; 
	scanf("%d", &x);
	return x;
}

int isFull(List *list) {
	return list->size == N;
}

int isEmpty(List *list) {
	return list->size == 0;
}

void insert_k(List **list, int k, int x) {
	if (isFull(*list)) return;
	if (k < 1 || k > (*list)->size + 1) return;

	for (int i = (*list)->size; i >= k; --i) 
		(*list)->elems[i] = (*list)->elems[i - 1];

	(*list)->size++;
	(*list)->elems[k - 1] = x;
}

void divideTwoList(List *list, List **positiveList, List **negativeList) {
	init(positiveList);
	init(negativeList);

	int n = list->size;

	for (int i = 0; i < n; ++i) {
		int x = list->elems[i];
		if (x > 0) {
			(*positiveList)->elems[(*positiveList)->size++] = x;
		} else {
			(*negativeList)->elems[(*negativeList)->size++] = x;
		}
	}
}


void inp(List **list) {
	printf("Nhap so luong phan tu cua danh sach: ");
	scanf("%d", &(*list)->size);

	for (int i = 0; i < (*list)->size; ++i) {
		(*list)->elems[i] = init_x();
	}
}

void displayList(List *list) {
	printf("Cac phan tu trong mang: ");
	for (int i = 0; i < list->size; ++i) 
		printf("%d ", list->elems[i]);
}

int main() {
	List *list;
	init(&list);

	// Test 1: Nhập dữ liệu
	printf("----- Test 1: Nhap du lieu -----\n");
	inp(&list);
	displayList(list);

	// Test 2: Thêm phần tử
	printf("----- Test 2: Them phan tu -----\n");
	int k, x;

	printf("Nhap vi tri k (1 den %d): ", list->size + 1);
	scanf("%d", &k);

	printf("Nhap gia tri phan tu can them: ");
	scanf("%d", &x);

	insert_k(&list, k, x);
	displayList(list);

	// Test 6: Thực hiện tách list thành 2 list chứa số âm và số dương.
	List *negativeList;
	List *positiveList;
	divideTwoList(list, &positiveList, &negativeList);

	printf("Danh sach cac so am: ");
	for (int i = 0; i < negativeList->size; ++i) 
		printf("%d ", negativeList->elems[i]);
	printf("\n");

	printf("Danh sach cac so duong: ");
	for (int i = 0; i < positiveList->size; ++i) 
		printf("%d ", positiveList->elems[i]);
	printf("\n");

	return 0;
}