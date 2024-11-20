/**
 *    author:  tourist
 *    created: 2024.11.20 14:43:15
**/

/**
 *    author:  tourist
 *    created: 2024.11.20 15:07:12
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node *next;
} Node;


typedef struct stack {
	Node *top;
} stack;

Node *makeNode(int x) {
	Node *newNode = (Node*)malloc(sizeof (Node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void init(stack **st) {
	(*st) = (stack*)malloc(sizeof (stack));
	(*st)->top = NULL;
}

int isEmpty(stack *st) {
	return (st->top == NULL);
}

void push(stack **st, int x) {
	Node *newNode = makeNode(x);
	newNode->next = (*st)->top;
	(*st)->top = newNode;
}

int pop(stack **st) {
	if (isEmpty(*st)) {
		printf("ngan xep rong\n");
		return -1;
	}

	int x = (*st)->top->data;
	Node *del = (*st)->top;

	(*st)->top = (*st)->top->next;
	free(del);

	return x;
}

void input(stack **st) {
	int n, x;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		printf("Nhap phan tu thu: %d ", i + 1);
		scanf("%d", &x);
		push(st, x);
	}
}

int size(stack *st) {
	int cnt = 0;
	Node *cur = st->top;

	while (cur != NULL) {
		++cnt;
		cur = cur->next;
	}

	return cnt;
}

void insertAtPosition(stack **st, int k, int x) {
	if (k < 1 || k > size(*st) + 1) {
		printf("Vi tri chen khong hop le\n");
		return;
	}

	Node *newNode = makeNode(x);

	if (k == 1) {
		newNode->next = (*st)->top;
		(*st)->top = newNode;
	} else {
		Node *cur = (*st)->top;
		for (int i = 1; i < k - 1; ++i) {
			cur = cur->next;
		}

		newNode->next = cur->next;
		cur->next = newNode;
	}
}

void display(stack *st) {
	if (isEmpty(st)) {
		printf("Ngan xep rong\n");
		return;
	}

	Node *cur = st->top;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int main() {
  stack *st;
  init(&st); // Khởi tạo ngăn xếp

  // Nhập dữ liệu cho ngăn xếp
  input(&st);
  
  // Hiển thị ngăn xếp
  printf("Cac phan tu trong ngan xep: ");
  display(st);

  // Thêm phần tử vào vị trí k
  int k, x;
  printf("Nhap vi tri k de chen phan tu moi: ");
  scanf("%d", &k);
  printf("Nhap phan tu can chen: ");
  scanf("%d", &x);
  
  insertAtPosition(&st, k, x);
  
  // Hiển thị ngăn xếp sau khi chen
  printf("Ngam xep sau khi chen tai vi tri k: ");
  display(st);

  // Xóa phần tử khỏi ngăn xếp
  printf("Popping elements from the stack:\n");
  while (!isEmpty(st)) {
    printf("Popped: %d\n", pop(&st));
    display(st);
  }

  // Giải phóng bộ nhớ
  free(st); // Giải phóng bộ nhớ cho ngăn xếp

	return 0;
}