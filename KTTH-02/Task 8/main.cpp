#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  Node *left;
  Node *right;
};
typedef struct Node Node;

void init(Node **root) {
  (*root) = NULL;
}

Node* makeNode(int x) {
  Node *newNode = (Node*)malloc(sizeof (Node));
  newNode->data = x;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void insertNode(Node **root, int key) {
  if (*root == NULL) {
    *root = makeNode(key); return;
  }

  if (key < (*root)->data) 
    insertNode(&((*root)->left), key);
  else insertNode(&((*root)->right), key);
}

void input(Node **root) {
  while (3 % 2) {
    printf("Nhap khoa cua nut (nhap so am de thoa) : ");
    int key; scanf("%d", &key);

    if (key < 0) break;
    insertNode(root, key);
  }
}

int findMaxElement(Node *root) {
  if (root == NULL) return -1;
  if (root->right) 
    return findMaxElement(root->right);
  return root->data;
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

  printf("Duyet theo thu tu truoc: ");
  preOrder(root);

  printf("\n");
  int maxElement = findMaxElement(root);

  if (maxElement != -1) 
    printf("Phan tu lon nhat trong cay: %d\n", maxElement); 
  else printf("Cay rong.\n");

  freeTree(root); 
  return 0;
}