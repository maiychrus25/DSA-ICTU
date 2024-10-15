#include <stdio.h>
#include <stdlib.h>

struct Node {
  char data;
  Node *left;
  Node *right;
};
typedef struct Node Node;

void initNode(Node **root) {
  *root = NULL;
}

Node* makeNode(char x) {
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

int countLeaf(Node *root) {
  if (root == NULL) return 0;
  if (isLeaf(root)) return 1;
  return countLeaf(root->left) + countLeaf(root->right);
}

Node* findNode(Node *root, char x) {
  if (root == NULL) return NULL;
  if (root->data == x) return root;

  Node *ans = findNode(root->left, x);
  if (ans != NULL) return ans;
  return findNode(root->right, x);
}

void preOrder(Node *root) {
  if (root == NULL) return;
  printf("%c ", root->data);
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node *root) {
  if (root == NULL) return;
  inOrder(root->left);
  printf("%c ", root->data);
  inOrder(root->right);
}

void insertRoot(Node **root, char u, char v, char c) {
  if (c == 'L') (*root)->left = makeNode(v);
  else if (c == 'R') (*root)->right = makeNode(v);
}

void insertNode(Node **root, char u, char v, char c) {
  if (*root == NULL) return;
  if ((*root)->data == u) insertRoot(root, u, v, c);
  else {
    insertNode(&((*root)->left), u, v, c);
    insertNode(&((*root)->right), u, v, c);
  }
}

void input(Node **root) {
  while (1) {
    printf("Nhap gia tri nut muon them (nhap so de thoat): ");
    char u; 
    scanf(" %c", &u);
    if (u >= '0' && u <= '9') break;

    printf("Nhap gia tri nut con: ");
    char v; 
    scanf(" %c", &v);

    printf("Nhap vi tri cua nut con (L -> Left), (R -> Right): ");
    char c; 
    scanf(" %c", &c);

    if (*root == NULL) {
      *root = makeNode(u);
      insertRoot(root, u, v, c);
    } else {
      insertNode(root, u, v, c);
    }
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

  printf("Du lieu theo thu tu giua: ");
  inOrder(root);
  printf("\n");

  printf("So nut la: %d\n", countLeaf(root));

  printf("Nhap gia tri nut can tim: ");
  char x; 
  scanf(" %c", &x);
  Node *foundNode = findNode(root, x);
  
  if (foundNode) 
    printf("Tim thay nut: %c\n", foundNode->data);
  else 
    printf("Khong tim thay nut.\n");

  freeTree(root); 
  return 0;
}
