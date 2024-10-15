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

void printOddDivisibleByThree(Node *root) {
  if (root == NULL) return;
  printOddDivisibleByThree(root->left);

  if (root->data % 2 != 0 && root->data % 3 == 0)
    printf("%d ", root->data);
  printOddDivisibleByThree(root->right);
}

Node* searchNode(Node *root, int key) {
  if (root == NULL || root->data == key)
    return root;

  if (key < root->data)
    return searchNode(root->left, key);
  return searchNode(root->right, key);
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

  printf("\nCac so le va chia het cho 3 trong cay: ");
  printOddDivisibleByThree(root);
  printf("\n");

  printf("Nhap khoa can tim: ");
  int key; scanf("%d", &key);

  Node *foundNode = searchNode(root, key);

  if (foundNode)
    printf("Tim thay nut co khoa: %d\n", foundNode->data);
  else
    printf("Khong tim thay nut co khoa: %d\n", key);

  freeTree(root);
  return 0;
}
