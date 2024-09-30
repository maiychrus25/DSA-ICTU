#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct stack {
  Node *top;
} stack;

Node *makeNode(int x) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = x;
  newNode->next = NULL;
  return newNode;
}

void init(stack **st) {
  (*st) = (stack*)malloc(sizeof(stack));
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
    printf("Ngan xep rong, khong the lay phan tu\n");
    return -1;
  }
  int x = (*st)->top->data;
  Node *del = (*st)->top;
  (*st)->top = (*st)->top->next;
  free(del);
  return x;
}

void display(stack *st) {
  if (isEmpty(st)) {
    printf("Ngan xep rong\n");
    return;
  }
  Node *tmp = st->top;
  printf("Cac phan tu trong ngan xep: ");
  while (tmp != NULL) {
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

void input(stack *st) {
  int n, x;
  printf("Nhap so luong phan tu: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("Nhap phan tu %d: ", i + 1);
    scanf("%d", &x);
    push(&st, x);
  }
}

void pushToBottom(stack *st, int x) {
  if (isEmpty(st)) {
    push(&st, x);
    return;
  }
  stack *temp;
  init(&temp);
  while (!isEmpty(st)) {
    push(&temp, pop(&st));
  }
  push(&st, x);
  while (!isEmpty(temp)) {
    push(&st, pop(&temp));
  }
}

void decimalToBinary(int n) {
  stack *st;
  init(&st);
  while (n > 0) {
    push(&st, n % 2);
    n = n / 2;
  }
  printf("So nhi phan: ");
  while (!isEmpty(st)) {
    printf("%d", pop(&st));
  }
  printf("\n");
}

int main() {
  stack *st;
  init(&st);
  input(st);
  display(st);

  int x;
  printf("Nhap phan tu can them vao day: ");
  scanf("%d", &x);
  pushToBottom(st, x);
  display(st);

  int n;
  printf("Nhap so nguyen duong de chuyen doi tu thap phan sang nhi phan: ");
  scanf("%d", &n);
  decimalToBinary(n);

  printf("Lay phan tu ra khoi ngan xep:\n");
  while (!isEmpty(st)) {
    printf("Phan tu bi lay ra: %d\n", pop(&st));
    display(st);
  }

  free(st);
  return 0;
}
