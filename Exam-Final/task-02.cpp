/**
 *    author:  tourist
 *    created: 2024.11.20 13:18:20
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 105;

typedef struct Student {
	char name[50];
	char gender[50];
	double gpa;
} Student;

typedef struct List {
	int size;
	Student elems[N];
} List;

void inpStudent(Student *a) {
	getchar();

	printf("Nhap ten sinh vien: ");
	fgets(a->name, 50, stdin);
	a->name[strcspn(a->name, "\n")] = 0;

	printf("Nhap gioi tinh sinh vien: ");
	fgets(a->gender, 50, stdin);
	a->gender[strcspn(a->gender, "\n")] = 0;

	printf("Nhap diem trung binh sinh vien: ");
	scanf("%lf", &a->gpa);

}

void displayStudent(Student a) {
	printf("Ten sinh vien: %s\n", a.name);
	printf("Gioi tinh sinh vien: %s\n", a.gender);
	printf("Diem trung binh sinh vien: %.2lf\n", a.gpa);
}

void initList(List **list) {
	(*list) = (List*)malloc(sizeof (List));
	(*list)->size = 0;
}

int isEmpty(List *list) {
	return list->size == 0;
}

int isFull(List *list) {
	return list->size == N;
}

void insert_k(List **list, int k, Student a) {
	if (isFull(*list)) return;
	if (k < 1 || k > (*list)->size + 1) return;

	for (int i = (*list)->size; i >= k; --i) 
		(*list)->elems[i] = (*list)->elems[i - 1];

	(*list)->size++;
	(*list)->elems[k - 1] = a;
}

void inpList(List **list) {
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &(*list)->size);

	printf("Nhap danh sach sinh vien: \n");
	for (int i = 0; i < (*list)->size; ++i) {
		inpStudent(&(*list)->elems[i]);
	}
}

void displayList(List *list) {
	printf("Danh sach sinh vien: \n");
	for (int i = 0; i < list->size; ++i) {
		displayStudent(list->elems[i]);
	}
}

void freeList(List *list) {
    free(list);
}

int main() {
	List *list;
	initList(&list);
	
	inpList(&list);
	displayList(list);

	printf("Nhap chi so can them: ");
	int k; scanf("%d", &k);

	Student a;
	inpStudent(&a);
	insert_k(&list, k, a);

	displayList(list);
	freeList(list);

	return 0;
}