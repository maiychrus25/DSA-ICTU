#include <stdio.h>
#include <stdlib.h>

#define N 10
typedef int item;

typedef struct Queue {
  item element[N];
  int size;
} Queue;

void createQueue(Queue **L) {
  *L = (Queue*)malloc(sizeof(Queue));
  (*L)->size = 0;
}

int isEmpty(Queue *L) {
  return (L->size == 0);
}

int isFull(Queue *L) {
  return (L->size == N);
}

void enqueue(Queue **L, item x) {
  if (isFull(*L)) {
    printf("Hang doi day\n");
  } 
  else {
    (*L)->element[(*L)->size] = x;
    (*L)->size++;
  }
}

void dequeue(Queue **L, item *x) {
  if (isEmpty(*L)) {
    printf("Hang doi rong\n");
  } 
  else {
    *x = (*L)->element[0];
    for (int i = 0; i < (*L)->size - 1; i++) {
      (*L)->element[i] = (*L)->element[i + 1];
    }
    (*L)->size--;
  }
}

void input(Queue **L) {
  item x;
  int n;
  createQueue(L);
  printf("Nhap so phan tu cua hang doi n= ");
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    printf("Nhap x= ");
    scanf("%d", &x);
    enqueue(L, x);
  }
}

void output(Queue *L) {
  if (isEmpty(L)) {
    printf("Hang doi rong\n");
  } 
  else {
    for (int i = 0; i < L->size; i++) {
      printf("%d\n", L->element[i]);
    }
  }
}

int locate(Queue *L, item x) {
  int pos = 0;
  
  while ((L->element[pos] != x) && (pos < L->size)) {
    pos++;
  }
  
  if (pos >= L->size) return 0;
  return pos + 1;
}

void dequeueAtPosition(Queue **L, int k, item *x) {
  if (isEmpty(*L)) {
    printf("Hang doi rong\n");
    return;
  }
  
  if (k < 1 || k > (*L)->size) {
    printf("Vi tri khong hop le\n");
    return;
  }

  *x = (*L)->element[k - 1];
  
  for (int i = k - 1; i < (*L)->size - 1; i++) {
    (*L)->element[i] = (*L)->element[i + 1];
  }
  
  (*L)->size--;
}

int main() {
  Queue *L;
  item x;
  input(&L);
  
  printf("Cac phan tu trong hang doi\n");
  output(L);
 
  printf("Nhap phan tu can chen x= ");
  scanf("%d", &x);
  enqueue(&L, x);

  printf("Cac phan tu trong hang doi sau khi chen\n");
  output(L);
 
  printf("Cac phan tu trong hang doi sau khi xoa\n");
  dequeue(&L, &x);
  output(L);
 
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
  
  dequeueAtPosition(&L, k, &x);
  printf("Phan tu lay ra tu vi tri k= %d\n", x);
  
  printf("Cac phan tu trong hang doi sau khi lay phan tu ra\n");
  output(L);
  
  free(L);
  return 0;
}