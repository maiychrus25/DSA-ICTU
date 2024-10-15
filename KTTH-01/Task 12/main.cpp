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

void displayOddAndDivisibleBy3(stack *st) {
  if (isEmpty(st)) {
    printf("Ngan xep rong\n");
    return;
  }
  Node *tmp = st->top;
  printf("Cac so le va chia het cho 3 trong ngan xep: ");
  while (tmp != NULL) {
    if (tmp->data % 2 != 0 && tmp->data % 3 == 0) {
      printf("%d ", tmp->data);
    }
    tmp = tmp->next;
  }
  printf("\n");
}

int main() {
  stack *st;
  init(&st);
  input(st);
  displayOddAndDivisibleBy3(st);

  printf("Lay phan tu ra khoi ngan xep:\n");
  while (!isEmpty(st)) {
    printf("Phan tu bi lay ra: %d\n", pop(&st));
  }

  free(st);
  return 0;
}
