/**
 *    author:  tourist
 *    created: 2024.11.20 19:53:44
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Staff {
	char name[50];
	char address[50];
	int salaryGrade;
} Staff;

typedef struct Node {
	Staff data;
	Node *next;
} Node;

// hàm tạo một node với dữ liệu lưu trữ là Cán bộ
Node* makeNode(Staff x) {
	Node *newNode = (Node*)malloc(sizeof (Node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

// hàm nhập thông tin của một Cán bộ
void inputStaff(Staff *staff) {
	getchar();

	printf("Nhap ten can bo: ");
	fgets(staff->name, 50, stdin);
	staff->name[strcspn(staff->name, "\n")] = 0;

	printf("Nhap dia chi can bo: ");
	fgets(staff->address, 50, stdin);
	staff->address[strcspn(staff->address, "\n")] = 0;

	printf("Nhap he so luong: ");
	scanf("%d", &staff->salaryGrade);
}

void insertLast(Node **head, Staff staff) {
	Node *newNode = makeNode(staff);
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

void eraseLast(Node **head) {
	if ((*head) == NULL) return;
	if ((*head)->next == NULL) {
		free(*head);
		(*head) = NULL;
		return;
	}

	Node *tmp = (*head);
	while (tmp->next->next != NULL) {
		tmp = tmp->next;
	}

	Node *del = tmp->next;
	tmp->next = NULL;
	free(del);
}

void input(Node **head) {
	printf("Nhap so can bo: ");
	int n; scanf("%d", &n);

	printf("Nhap thong cho moi can bo: ");
	for (int i = 0; i < n; ++i) {
		Staff staff;
		inputStaff(&staff);
		insertLast(head, staff);
	}
}

void displayStaff(Staff staff) {
	printf("Ten can bo: %s\n", staff.name);
	printf("Dia chi can bo: %s\n", staff.address);
	printf("He so luong: %d\n", staff.salaryGrade);
}

void display(Node *head) {
	if (head == NULL) return;
	while (head != NULL) {
		displayStaff(head->data);
		head = head->next;
	}
}

int main() {
	Node *head = NULL;
  input(&head);
  display(head);
	return 0;
}
