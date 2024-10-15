#include <stdio.h>
#include <stdlib.h>

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
    printf("Nhap khoa cua nut (nhap 0 de thoat): ");
    int key; scanf("%d", &key);
    
    if (key == 0) break;
    insertNode(root, key);
  }
}

Node* searchNode(Node *root, int key) {
  if (root == NULL || root->data == key)
    return root;

  if (key < root->data)
    return searchNode(root->left, key);
  return searchNode(root->right, key);
}

void printOddNumbers(Node *root) {
  if (root == NULL) return;
  printOddNumbers(root->left);

  if (root->data % 2 != 0)
    printf("%d ", root->data);
  printOddNumbers(root->right);
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

  printf("\nNhap khoa can tim: ");
  int key; scanf("%d", &key);

  Node *foundNode = searchNode(root, key);

  if (foundNode)
    printf("Tim thay nut co khoa: %d\n", foundNode->data);
  else
    printf("Khong tim thay nut co khoa: %d\n", key);

  printf("\nCac so le trong cay: ");
  printOddNumbers(root);
  printf("\n");

  freeTree(root);
  return 0;
}
