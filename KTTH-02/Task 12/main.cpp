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

void inOrder(Node *root) {
  if (root == NULL) return;
  inOrder(root->left);

  printf("%d ", root->data);
  inOrder(root->right);
}

void printEvenNumbers(Node *root) {
  if (root == NULL) return;
  printEvenNumbers(root->left);

  if (root->data % 2 == 0)
    printf("%d ", root->data);
  printEvenNumbers(root->right);
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

  printf("\nDuyet theo thu tu giua: ");
  inOrder(root);
  
  printf("\n\nCac so chan trong cay: ");
  printEvenNumbers(root);
  printf("\n");

  freeTree(root);
  return 0;
}
