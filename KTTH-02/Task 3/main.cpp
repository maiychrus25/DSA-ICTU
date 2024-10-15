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

int isLeaf(Node *root) {
  return root && root->left == NULL && root->right == NULL;
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
    if (u & 1) break;

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

void postOrder(Node *root) {
  if (root == NULL) return;
  postOrder(root->left);

  postOrder(root->right);
  printf("%d ", root->data);
}

int findMaxEven(Node *root) {
  if (root == NULL) return -1;
  int maxEven = (root->data % 2 == 0) ? root->data : -1;
  
  int leftMax = findMaxEven(root->left);
  int rightMax = findMaxEven(root->right);

  if (leftMax > maxEven) maxEven = leftMax;
  if (rightMax > maxEven) maxEven = rightMax;
  
  return maxEven;
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
  
  printf("Du lieu theo thu tu sau: ");
  postOrder(root);

  printf("\n");
  int maxEven = findMaxEven(root);
  
  if (maxEven != -1) {
    printf("Gia tri chan lon nhat: %d\n", maxEven);
  } 
  else {
    printf("Khong tim thay gia tri chan.\n");
  }

  freeTree(root);
  return 0;
}
