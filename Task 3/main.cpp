#include <stdio.h>
#include <stdlib.h>

const int N = 105;
typedef int item;

typedef struct List {
    int size;
    item elems[N];
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

item init_x() {
    int x;
    scanf("%d", &x);
    return x;
}

void inp(List **list) {
    printf("Nhap so luong phan tu cua danh sach: ");
    scanf("%d", &(*list)->size);

    for (int i = 0; i < (*list)->size; ++i) {
        (*list)->elems[i] = init_x();
    }
}

int insert_k(List **list, int k, item x) {
    if (isFull(*list)) return -1;
    if (k < 1 || k > (*list)->size + 1) return 0;

    printf("Nhap gia tri x: ");
    x = init_x();

    for (int i = (*list)->size; i >= k; --i) 
        (*list)->elems[i] = (*list)->elems[i - 1];

    (*list)->size++; // Tang kich co mang len 1 khi them duoc x
    (*list)->elems[k - 1] = x; // Gan gia tri tai k - 1 = x

    return 1;
}

int del_k(List **list, item *x, int k) {
    if (isEmpty(*list)) return -1;
    if (k < 1 || k > (*list)->size) return 0;

    *x = (*list)->elems[k - 1];
    for (int i = k - 1; i < (*list)->size - 1; ++i) 
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
    while (idx) {
        del_k(list, &x, idx);
        idx = search(*list, x);
    }
    return 1;
}

double calcAverage(List *list) {
    int cnt = 0;
    double sum = 0;

    for (int i = 0; i < list->size; ++i) {
        if (list->elems[i] > 0) {
            cnt++; 
            sum += list->elems[i];
        }
    }
    return (cnt > 0) ? (sum / cnt) : 0; // Tránh chia cho 0
}

int* findPosElement(List *list, item x, int *idx) {
    (*idx) = 0;
    int *ans = (int *)malloc(N * sizeof(int));
    
    if (ans == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < list->size; ++i) {
        if (list->elems[i] == x) ans[(*idx)++] = i + 1;
    }

    return ans;
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
    } else {
        printf("Phan tu %d khong tim thay.\n", searchValue);
    }

    // Test 5: Xóa tất cả phần tử có giá trị x
    printf("----- Test 5: Xoa tat ca phan tu co gia tri -----\n");
    printf("Nhap gia tri can xoa: ");
    
    item xToDelete = init_x();
    del_x(&list, xToDelete);
    
    display(list);

    // Test 6: Viết hàm trả về vị trí và giá trị của tất cả các phần tử có giá trị x trong danh sách
    printf("----- Test 6: Tim cac vi tri -----\n");
    printf("Nhap phan tu can tim: ");
    item v = init_x();

    int cnt;
    int *ans = findPosElement(list, v, &cnt);
    printf("Cac vi tri co gia tri bang %d: ", v);

    for (int i = 0; i < cnt; ++i) 
        printf("%d ", ans[i]);
    
    printf("\n");
    
    free(ans); // Giải phóng mảng vị trí

    // Giải phóng bộ nhớ
    free(list);
}

int main() {
    runTests();
    return 0;
}
