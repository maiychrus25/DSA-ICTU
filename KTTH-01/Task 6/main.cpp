#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 105;

typedef struct Student {
    char name[N];
    char gender[N];
    double gpa;
} Student;

typedef struct List {
    int size;
    Student elems[N];
} List;

void init(List **list) {
    (*list) = (List*)malloc(sizeof(List));
    (*list)->size = 0;
}

int isEmpty(List *list) {
    return list->size == 0;
}

int isFull(List *list) {
    return list->size == N;
}

Student inpStudent() {
  Student sv;
  printf("Nhap ho ten: ");
  scanf(" %[^\n]", sv.name);

  printf("Nhap gioi tinh: ");
  scanf(" %[^\n]", sv.gender); 

  printf("Nhap diem GPA: ");
  scanf("%lf", &sv.gpa); 
  return sv;
}

// Nhập danh sách sinh viên
void inp(List **list) {
  printf("Nhap so luong sinh vien: ");
  scanf("%d", &(*list)->size);

  for (int i = 0; i < (*list)->size; ++i) {
    printf("Nhap thong tin sinh vien %d:\n", i + 1);
    (*list)->elems[i] = inpStudent();
  }
}

// Hiển thị danh sách sinh viên
void display(List *list) {
  printf("Danh sach sinh vien:\n");
  for (int i = 0; i < list->size; ++i) {
    printf("Sinh vien %d: Ho ten: %s, Gioi tinh: %s, GPA: %.2f\n", 
      i + 1, list->elems[i].name, list->elems[i].gender, list->elems[i].gpa);
  }
}

// Đếm số lượng sinh viên nữ có GPA > 9.0
int countFemaleStudentsWithHighGPA(List *list) {
  int count = 0;
  for (int i = 0; i < list->size; ++i) {
    if (strcmp(list->elems[i].gender, "Nu") == 0 && list->elems[i].gpa > 9.0) {
      count++;
    }
  }
  return count;
}

// Hàm chính để chạy chương trình
void runTests() {
  List *list;
  init(&list);
  
  inp(&list);
  display(list);
  
  int femaleCount = countFemaleStudentsWithHighGPA(list);
  printf("So luong sinh vien nu co GPA > 9.0: %d\n", femaleCount);

  free(list);
}

int main() {
  runTests();
  return 0;
}
