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
    printf("Nhap khoa cua nut (nhap ky tu de thoat): ");
    char c; scanf("%s", &c);

    if (!isdigit(c)) break;

    int key = (c - '0');
    insertNode(root, key);
  }
}

void inOrder(Node *root) {
  if (root == NULL) return;
  inOrder(root->left);

  printf("%d ", root->data);
  inOrder(root->right);
}

int findMinElement(Node *root) {
  if (root == NULL) return -1; 

  if (root->left) 
    return findMinElement(root->left);
  return root->data;
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

  printf("\n");
  int minElement = findMinElement(root);

  if (minElement != -1) 
    printf("Phan tu nho nhat trong cay: %d\n", minElement); 
  else 
    printf("Cay rong.\n");

  freeTree(root); 
  return 0;
}
