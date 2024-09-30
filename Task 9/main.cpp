#include <stdio.h>
#include <stdlib.h>

const int N = 105;

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct queue {
  int size;
  Node *front;
  Node *rear;
} queue;

Node* makeNode(int x) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = x;
  newNode->next = NULL;
  return newNode;
}

void init(queue **q) {
  (*q) = (queue*)malloc(sizeof(queue));
  (*q)->size = 0;
  (*q)->front = NULL;
  (*q)->rear = NULL;
}

int isEmpty(queue *q) {
  return q->size == 0;
}

// Thêm phần tử vào cuối hàng đợi
void push(queue **q, int x) {
  Node *newNode = makeNode(x);
  if (isEmpty(*q)) {
    (*q)->front = (*q)->rear = newNode;
  } 
  else {
    (*q)->rear->next = newNode;
    (*q)->rear = newNode;
  }
  (*q)->size++;
}

// Xóa phần tử ở đầu hàng đợi
int pop(queue **q) {
  if (isEmpty(*q)) return -1;
  else {
    int x = (*q)->front->data;
    Node *del = (*q)->front;

    if ((*q)->size == 1) {
      free(del);
      init(q);
    } 
    else {
      (*q)->front = (*q)->front->next;
      free(del);
    }
    (*q)->size--;
    return x;
  }
}

// Nhập dữ liệu cho hàng đợi
void input(queue **q) {
  int n, x;
  printf("Nhap so luong phan tu: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("Nhap phan tu %d: ", i + 1);
    scanf("%d", &x);
    push(q, x);
  }
}

// Hiển thị dữ liệu trong hàng đợi
void display(queue *q) {
  if (isEmpty(q)) return;
  Node *cur = q->front;

  while (cur != NULL) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
  printf("\n");
}

// Thêm phần tử vào vị trí k bất kỳ trong hàng đợi
void insertAtPosition(queue **q, int k, int x) {
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
  } 
  else {
    Node *cur = (*q)->front;
    for (int i = 1; i < k - 1; i++) {
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
  queue *q;
  init(&q); // Khởi tạo hàng đợi

  // Nhập dữ liệu cho hàng đợi
  input(&q);
  
  // Hiển thị hàng đợi
  printf("Cac phan tu trong hang doi: ");
  display(q);

  // Xóa phần tử đầu hàng đợi
  int popped = pop(&q);
  printf("Phan tu pop: %d\n", popped);

  // Hiển thị hàng đợi sau khi pop
  printf("Hang doi sau khi pop: ");
  display(q);

  // Thêm phần tử vào vị trí k
  int k, x;
  printf("Nhap vi tri k de chen phan tu moi: ");
  scanf("%d", &k);
  printf("Nhap phan tu can chen: ");
  scanf("%d", &x);
  
  insertAtPosition(&q, k, x);
  
  // Hiển thị hàng đợi sau khi chen
  printf("Hang doi sau khi chen tai vi tri k: ");
  display(q);

  // Giải phóng bộ nhớ
  while (!isEmpty(q)) {
    pop(&q);
  }
  free(q); 

  return 0;
}
