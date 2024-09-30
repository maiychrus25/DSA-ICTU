#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node* makeNode(int x) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = x;
  newNode->next = NULL;
  return newNode;
}

void insertHead(Node **head, int x) {
  Node *newNode = makeNode(x);
  newNode->next = (*head);
  (*head) = newNode;
}

void insertLast(Node **head, int x) {
  Node *newNode = makeNode(x);
  if ((*head) == NULL) {
    (*head) = newNode;
    return;
  }

  Node *tmp = (*head);
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = newNode;
}

int count(Node *head) {
  int cnt = 0;
  while (head != NULL) {
    cnt++;
    head = head->next;
  }
  return cnt;
}

void insertMid(Node **head, int k, int x) {
  if (k < 1 || k > count(*head) + 1) return;
  if (k == 1) {
    insertHead(head, x);
  } 
  else {
    Node *newNode = makeNode(x);
    Node *tmp = (*head);
    
    for (int cnt = 1; cnt < k - 1; cnt++) {
      tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
  }
}

void eraseFirst(Node **head) {
  if (*head == NULL) return;
  Node *del = *head;
  *head = (*head)->next;
  free(del);
}

void eraseLast(Node **head) {
  if (*head == NULL) return;
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }
  Node *tmp = *head;
  while (tmp->next->next != NULL) {
      tmp = tmp->next;
  }
  Node *del = tmp->next;
  tmp->next = NULL;
  free(del);
}

void eraseMid(Node **head, int k) {
  if (*head == NULL) return;
  if (k < 1 || k > count(*head)) return;

  if (k == 1) {
    eraseFirst(head);
    return;
  }

  Node *tmp = *head;
  for (int cnt = 1; cnt < k - 1; cnt++) {
    tmp = tmp->next;
  }

  Node *del = tmp->next;
  tmp->next = tmp->next->next;
  free(del);
}

// Xóa mọi phần tử có giá trị x xuất hiện trong linked list
void eraseAll(Node **head, int x) {
  if (*head == NULL) return;
  Node *last = *head, *first = NULL;
  while (last != NULL) {
    if (last->data == x) {
      Node *del = last;
      if (first == NULL) {
        *head = (*head)->next;
        last = *head;
      } 
      else {
        first->next = last->next;
        last = last->next;
      }
      free(del);
    } 
    else {
      first = last;
      last = last->next;
    }
  }
}

double calcAverage(Node *head) {
  int cnt = 0;
  double sum = 0;

  while (head != NULL) {
    if (head->data > 0) {
      cnt++;
      sum += head->data;
    }
    head = head->next;
  }

  return (cnt > 0 ? sum / cnt : 0);
}

// Hàm hiển thị danh sách
void display(Node *head) {
  while (head != NULL) {
      printf("%d ", head->data);
      head = head->next;
  }
  printf("\n");
}

// Các bài test
void runTests() {
  Node *head = NULL;

  // Test 1: Thêm phần tử vào đầu danh sách
  printf("Test 1: Them phan tu vao dau\n");
  insertHead(&head, 5);
  insertHead(&head, 10);
  insertHead(&head, 15);
  display(head); // Kỳ vọng: 15 10 5

  // Test 2: Thêm phần tử vào cuối danh sách
  printf("Test 2: Them phan tu vao cuoi\n");
  insertLast(&head, 20);
  insertLast(&head, 25);
  display(head); // Kỳ vọng: 15 10 5 20 25

  // Test 3: Thêm phần tử vào giữa danh sách
  printf("Test 3: Them phan tu vao giua\n");
  insertMid(&head, 3, 30); // Thêm 30 vào vị trí thứ 3
  display(head); // Kỳ vọng: 15 10 30 5 20 25

  // Test 4: Xóa phần tử đầu danh sách
  printf("Test 4: Xoa phan tu dau\n");
  eraseFirst(&head);
  display(head); // Kỳ vọng: 10 30 5 20 25

  // Test 5: Xóa phần tử cuối danh sách
  printf("Test 5: Xoa phan tu cuoi\n");
  eraseLast(&head);
  display(head); // Kỳ vọng: 10 30 5 20

  // Test 6: Xóa phần tử ở giữa danh sách
  printf("Test 6: Xoa phan tu o giua\n");
  eraseMid(&head, 2); // Xóa phần tử ở vị trí thứ 2
  display(head); // Kỳ vọng: 10 5 20

  // Test 7: Xóa tất cả phần tử có giá trị x
  printf("Test 7: Xoa tat ca phan tu co gia tri 20\n");
  insertLast(&head, 20);
  insertLast(&head, 20);
  insertLast(&head, 30);
  display(head); // Kỳ vọng: 10 5 20 20 30
  eraseAll(&head, 20);
  display(head); // Kỳ vọng: 10 5 30

  // Giải phóng bộ nhớ
  while (head != NULL) {
      eraseFirst(&head);
  }
}

int main() {
  runTests();
  return 0;
}
