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
    printf("Nhap khoa cua nut (nhap so le de thoat): ");
    int key;
    scanf("%d", &key);
    if (key % 2 != 0) break;
    insertNode(root, key);
  }
}

void inOrder(Node *root) {
  if (root == NULL) return;
  inOrder(root->left);
  
  printf("%d ", root->data);
  inOrder(root->right);
}

void preOrder(Node *root) {
  if (root == NULL) return;
  printf("%d ", root->data);

  preOrder(root->left);
  preOrder(root->right);
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

  printf("Duyet theo thu tu giua: ");
  inOrder(root);

  printf("\nDuyet theo thu tu truoc: ");
  preOrder(root);

  printf("\n");
  freeTree(root);

  return 0;
}
