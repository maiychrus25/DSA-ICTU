#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};
typedef struct Node Node;

void init(Node **root) {
  *root = NULL;
}

Node* makeNode(int x) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = x;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void insertNode(Node **root, int key) {
  if (*root == NULL) {
    *root = makeNode(key);
    return;
  }
  if (key < (*root)->data) 
    insertNode(&((*root)->left), key);
  else 
    insertNode(&((*root)->right), key);
}

void input(Node **root) {
  while (1) {
    printf("Nhap khoa cua nut (nhap so chan de thoat): ");
    char c; scanf(" %c", &c);  

    if (!isdigit(c)) break;  

    int key = c - '0';  
    if (key % 2 == 0) break; 
    insertNode(root, key);
  }
}

Node* searchNode(Node *root, int key) {
  if (root == NULL || root->data == key) {
    return root;
  }
  if (key < root->data) {
    return searchNode(root->left, key);
  }
  return searchNode(root->right, key);
}

void postOrder(Node *root) {
  if (root == NULL) return;
  postOrder(root->left);

  postOrder(root->right);
  printf("%d ", root->data);
}

void freeTree(Node *root) {
  if (root == NULL) return;
  freeTree(root->left);

  freeTree(root->right);
  free(root);
}

int main() {
  Node *root;
  init(&root); 

  input(&root);

  printf("Duyet theo thu tu sau: ");
  postOrder(root);
  printf("\n");

  printf("Nhap khoa can tim: ");
  int searchKey; 

  scanf("%d", &searchKey);
  Node *foundNode = searchNode(root, searchKey);

  if (foundNode) 
    printf("Tim thay node: %d\n", foundNode->data); 
  else 
    printf("Khong tim thay node.\n");

  freeTree(root); 
  return 0;
}
