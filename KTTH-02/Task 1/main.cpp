#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  Node *left;
  Node *right;
};
typedef struct Node Node;

void initNode(Node **root) {
  (*root) = NULL;
}

Node* makeNode(int x) {
  Node *newNode = (Node*)malloc(sizeof (Node));
  newNode->data = x;

  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

int isEmpty(Node *root) {
  return root == NULL;
}

Node* leftChild(Node *root) {
  return (!isEmpty(root) ? root->left : NULL);
}

Node* rightChild(Node *root) {
  return (!isEmpty(root) ? root->right : NULL);
}

int isLeaf(Node *root) {
  return (root->left == NULL && root->right == NULL);
}

int countLeaf(Node *root) {
  if (root == NULL) return 0;
  if (isLeaf(root)) return 1;
  return countLeaf(root->left) + countLeaf(root->right);
}

Node* findNode(Node *root, int x) {
  if (root == NULL) return NULL;
  if (root->data == x) return root;

  Node *ans = findNode(root->left, x);
  if (ans != NULL) return ans;
  return findNode(root->right, x);
}

void preOrder(Node *root) {
  if (root == NULL) return;
  printf("%d ", root->data);

  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node *root) {
  if (root == NULL) return;
  inOrder(root->left);

  printf("%d ", root->data);
  inOrder(root->right);
}

void postOrder(Node *root) {
  if (root == NULL) return;
  postOrder(root->left);

  postOrder(root->right);
  printf("%d ", root->data);
}

void insertRoot(Node **root, int u, int v, char c) {
  if (c == 'L') (*root)->left = makeNode(v);
  else (*root)->right = makeNode(v);
}

void insertNode(Node **root, int u, int v, char c) {
  if ((*root) == NULL) return;
  if ((*root)->data == u) insertRoot(root, u, v, c);
  else {
    insertNode(&((*root)->left), u, v, c);
    insertNode(&((*root)->right), u, v, c);
  }
}

void input(Node **root) {
  while (2 > 1) {
    printf("Nhap ki tu q de thoat!");
    char isExit; scanf(" %c", &isExit);
    if (isExit == 'q') break;

    printf("Nhap gia tri nut muon them nut con: ");
    int u; scanf("%d", &u);
  
    printf("Nhap gia tri nut con: ");
    int v; scanf("%d", &v);

    printf("Nhap vi tri cua not con (L -> Left), (R -> right): ");
    char c; scanf(" %c", &c);

    if ((*root) == NULL) {
      (*root) = makeNode(u);
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

  input(&root); // Nhập dữ liệu cho cây

  printf("Pre-order: ");
  preOrder(root);
  printf("\n");

  printf("Số nút lá: %d\n", countLeaf(root));

  printf("Nhap gia tri nut can tim: ");
  int x; scanf("%d", &x);
  Node *foundNode = findNode(root, x);
  
  if (foundNode) printf("Tim thay nut: %d\n", foundNode->data);
  else printf("Khong tim thay nut.\n");

  freeTree(root); 
  return 0;
}