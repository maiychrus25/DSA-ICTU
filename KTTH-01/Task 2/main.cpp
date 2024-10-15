#include <stdio.h>
#include <stdlib.h>

typedef int item;
const int N = 105;

typedef struct List {
  int size;
  item elems[N];
} List;

void init(List **list) {
  (*list) = (List*)malloc(sizeof (List));
  (*list)->size = 0;
}

item init_x() {
  int x;
  scanf("%d", &x);
  return x;
}

int isEmpty(List *list) {
  return (list->size == 0);
}

int isFull(List *list) {
  return (list->size == N);
}

void inp(List **list) {
  printf("Nhap so luong phan tu cua danh sach: ");
  scanf("%d", &(*list)->size);

  for (int i = 0; i < (*list)->size; ++i)
    (*list)->elems[i] = init_x();
}

int insert_k(List **list, int k, item x) {
  if (isFull(*list)) return -1;
  if (k < 1 || k - 1 > (*list)->size) return 0;

  printf("Nhap gia tri x: ");
  scanf("%d", &x);

  for (int i = (*list)->size; i >= k; --i) 
    (*list)->elems[i] = (*list)->elems[i - 1];

  (*list)->size++;
  (*list)->elems[k - 1] = x;

  return 1;
}

int del_k(List **list, item *x, int k) {
  if (isEmpty(*list)) return -1;
  if (k < 1 || k > (*list)->size) return 0;

  *x = (*list)->elems[k - 1];
  for (int i = k - 1; k < (*list)->size; ++i) 
    (*list)->elems[i] = (*list)->elems[i + 1];

  (*list)->size--;
  return 1;
}

int search(List *list, item x) {
  for (int i = 0; i < list->size; ++i) 
    if (list->elems[i] == x) return i + 1;
  return 0;
}

int del_x(List **list, item x) {
  if (isEmpty(*list)) return -1;
  int idx = search(*list, x);

  if (idx == 0) return 0;
  while (idx != 0) {
    del_k(list, &x, idx);
    idx = search(*list, x);
  }
  return 1;
}

void divideTwoList(List **list, List **evenList, List **oddList) {
  init(oddList);
  init(evenList);

  int n = (*list)->size;
  for (int i = 0; i < n; ++i) {
    item x = (*list)->elems[i];
    if (x & 1) (*oddList)->elems[(*oddList)->size++] = x;
    else (*evenList)->elems[(*evenList)->size++] = x;
  }
}

void display(List *list) {
  printf("Danh sach cac phan tu: ");
  for (int i = 0; i < list->size; ++i) 
    printf("%d ", list->elems[i]);
  printf("\n");
}

void runTests() {
  List *list;
  init(&list);
  
  // Test 1: Nhập dữ liệu
  printf("----- Test 1: Nhap du lieu -----\n");
  inp(&list);
  display(list);

  // Test 2: Thêm phần tử
  printf("----- Test 2: Them phan tu -----\n");
  int k; item x;
  
  printf("Nhap vi tri k (1 den %d): ", list->size + 1);
  scanf("%d", &k);
  
  insert_k(&list, k, x);
  display(list);

  // Test 3: Xóa phần tử
  printf("----- Test 3: Xoa phan tu -----\n");
  item removedItem;
  
  printf("Nhap vi tri k de xoa (1 den %d): ", list->size);
  scanf("%d", &k);
  
  del_k(&list, &removedItem, k); // Xóa phần tử tại vị trí k
  printf("Phan tu bi xoa: %d\n", removedItem);
  display(list);

  // Test 4: Tìm kiếm phần tử
  printf("----- Test 4: Tim kiem phan tu -----\n");
  printf("Nhap gia tri can tim: ");
  
  item searchValue = init_x();
  int foundIndex = search(list, searchValue);
  
  if (foundIndex) {
      printf("Phan tu %d tim thay tai vi tri: %d\n", searchValue, foundIndex);
  } 
  else {
      printf("Phan tu %d khong tim thay.\n", searchValue);
  }

  // Test 5: Xóa tất cả phần tử có giá trị x
  printf("----- Test 5: Xoa tat ca phan tu co gia tri -----\n");
  printf("Nhap gia tri can xoa: ");
  
  item xToDelete = init_x();
  del_x(&list, xToDelete);
  
  display(list);

  // // Test 6: Thực hiện tách list thành 2 list chứa số âm và số dương
  List *evenList;
  List *oddList;
  divideTwoList(&list, &evenList, &oddList);

  printf("Danh sach cac so chan: ");
  for (int i = 0; i < evenList->size; ++i) 
    printf("%d ", evenList->elems[i]);
  printf("\n");

  printf("Danh sach cac so le: ");
  for (int i = 0; i < oddList->size; ++i) 
    printf("%d ", oddList->elems[i]);
  printf("\n");

  // Giải phóng bộ nhớ
  free(list);
}

int main() {
  runTests();
  return 0;
}