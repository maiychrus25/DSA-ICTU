#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct stack {
  int data[MAX];
  int top;
} stack;

void init(stack *st) {
  st->top = -1;
}

int isEmpty(stack *st) {
  return st->top == -1;
}

int isFull(stack *st) {
  return st->top == MAX - 1;
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
    printf("Ngan xep rong, khong the lay phan tu\n");
    return -1;
  }
  return st->data[st->top--];
}

void input(stack *st) {
  int n, x;
  printf("Nhap so luong phan tu: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("Nhap phan tu %d: ", i + 1);
    scanf("%d", &x);
    push(st, x);
  }
}

void displayEven(stack *st) {
  if (isEmpty(st)) {
    printf("Ngan xep rong\n");
    return;
  }
  printf("Cac so chan trong ngan xep: ");
  for (int i = 0; i <= st->top; i++) {
    if (st->data[i] % 2 == 0) {
      printf("%d ", st->data[i]);
    }
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
  
  displayEven(&st);

  int n;
  printf("Nhap so nguyen duong de chuyen doi tu thap phan sang nhi phan: ");
  scanf("%d", &n);
  decimalToBinary(n);

  printf("Lay phan tu ra khoi ngan xep:\n");
  while (!isEmpty(&st)) {
    printf("Phan tu bi lay ra: %d\n", pop(&st));
  }

  return 0;
}
