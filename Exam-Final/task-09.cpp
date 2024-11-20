/**
 *    author:  tourist
 *    created: 2024.11.20 19:33:15
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node *next;
} Node;

Node *makeNode(int x) {
	Node *newNode = (Node*)malloc(sizeof (Node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

int count(Node *head) {
	if (head == NULL) return 0;
	return 1 + count(head->next);
}

void insertHead(Node **head, int x) {
	Node *newNode = makeNode(x);
	newNode->next = (*head);
	(*head) = newNode;
}

// Phần đề bài dạng 9 không yêu cầu
void insertMid(Node **head, int k, int x) {
	if (k < 1 || k > count(*head) + 1) return;
	if (k == 1) insertHead(head, x);
	else {
		Node *tmp = (*head);
		Node *newNode = makeNode(x);
	
		for (int i = 1; i < k - 1; ++i) {
			tmp = tmp->next;
		}

		newNode->next = tmp->next;
		tmp->next = newNode;
	}
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
// Kết thúc phần không yêu cầu của dạng 9

// hàm đếm các số lẻ và chia hết cho 3
int countOddAndDivisibleByThree(Node *head) {
	if (head == NULL) return 0;
	if (head->data % 2 && head->data % 3 == 0) 
		return 1 + countOddAndDivisibleByThree(head->next);
	return countOddAndDivisibleByThree(head->next);
}

void input(Node **head) {
  printf("Nhap so luong phan tu: ");
  int n; scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    printf("Nhap gia tri thu: %d= ", i + 1);
    int x; scanf("%d", &x);
    insertHead(head, x);
}

void display(Node *head) {
  printf("Cac phan tu trong danh sach: \n");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}

int main() {
  Node *head = NULL;
  input(&head);
  display(head);
	return 0;
}
