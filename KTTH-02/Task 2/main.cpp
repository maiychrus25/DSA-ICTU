#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};
typedef struct Node Node;

void initNode(Node **root) {
  *root = NULL;
}

Node* makeNode(int x) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = x;

  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

int isEmpty(Node *root) {
  return root == NULL;
}

Node* findLeftChild(Node *root) {
  return root ? root->left : NULL;
}

Node* findRightChild(Node *root) {
  return root ? root->right : NULL;
}

int isLeaf(Node *root) {
  return root->left == NULL && root->right == NULL;
}

int countLeaf(Node *root) {
  if (root == NULL) return 0;
  if (isLeaf(root)) return 1;
  return countLeaf(root->left) + countLeaf(root->right);
}

void inOrder(Node *root) {
  if (root == NULL) return;
  inOrder(root->left);

  printf("%d ", root->data);
  inOrder(root->right);
}

void insertRoot(Node **root, int u, int v, char c) {
  if (c == 'L') (*root)->left = makeNode(v);
  else (*root)->right = makeNode(v);
}

void insertNode(Node **root, int u, int v, char c) {
  if (*root == NULL) return;
  if ((*root)->data == u) insertRoot(root, u, v, c);
  else {
    insertNode(&((*root)->left), u, v, c);
    insertNode(&((*root)->right), u, v, c);
  }
}

void input(Node **root) {
  while (1) {
    printf("Nhap gia tri nut muon them (so nguyen am de thoat): ");
    int u; scanf("%d", &u);
    if (u < 0) break;

    printf("Nhap gia tri nut con: ");
    int v; scanf("%d", &v);

    printf("Nhap vi tri cua nut con (L -> Left), (R -> Right): ");
    char c; scanf(" %c", &c);

    if (*root == NULL) {
      *root = makeNode(u);
      insertRoot(root, u, v, c);
    } 
    else insertNode(root, u, v, c);
  }
}

void freeTree(Node *root) {
  if (root == NULL) return;
  freeTree(root->left);

  freeTree(root->right);
  free(root);
}

int main() {
  Node *root;
  initNode(&root);
  input(&root);

  printf("In-order: ");
  inOrder(root);
  printf("\n");

  printf("So nut la: %d\n", countLeaf(root));

  freeTree(root);
  return 0;
}
