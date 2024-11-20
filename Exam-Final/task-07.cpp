/**
 *    author:  tourist
 *    created: 2024.11.20 19:03:22
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node *left;
	Node *right;
} Node;

Node *makeNode(int x) {
	Node *newNode = (Node*)malloc(sizeof (Node));
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void initNode(Node **root) {
  (*root) = NULL;
}


int isEmpty(Node *root) {
	return (root == NULL);
}

// Dang 7 trong file cua co thi phan nay khong can
Node *leftChild(Node *root) {
	return (!isEmpty(root) ? root->left : NULL);
}

Node *rightChilde(Node *root) {
	return (!isEmpty(root) ? root->right : NULL);
}
// Ket thuc phan khong nam trong dang 7 cua co

// Hàm kiếm tra một node có phải là lá không
int isLeaf(Node *root) {
	return (root->left == NULL && root->right == NULL);
}

// Hàm đếm số node lá trên cây
int countLeaft(Node *root) {
	if (root == NULL) return 0;
	if (isLeaf(root)) return 1;
	return countLeaft(root->left) + countLeaft(root->right);
}

// hàm tìm một node
Node *findNode(Node *root, int x) {
	if (root == NULL) return NULL;
	if (root->data == x) return root;

	Node *ans = findNode(root->left, x);
	if (ans != NULL) return ans;
	return findNode(root->right, x);
}

// hàm in ra theo thứ tự trước
void preOrder(Node *root) {
	if (root == NULL) return;	
	printf("%d ", root->data);

	preOrder(root->left);
	preOrder(root->right);
}

// hàm thêm một node vào cây
void insertRoot(Node **root, int u, int v, char c) {
	if (c == 'L') (*root)->left = makeNode(v);
	else (*root)->right = makeNode(v);
}

// hàm tìm vị trí chèn
void insertNode(Node **root, int u, int v, char c) {
	if ((*root) == NULL) return;
	if ((*root)->data == u) insertRoot(root, u, v, c);
	else {
		insertNode(&(*root)->left, u, v, c);
		insertNode(&(*root)->right, u, v, c);
	}
}

// hàm nhập của cây
void input(Node **root) {
	while (true) {
		printf("Nhap gia tri cua nut muon them nut con (0 de thoat): ");
		int u; scanf("%d", &u);

		// xử lý nếu nhập vào số 0 thì kết thúc nhập
		if (u == 0) return;

		printf("Nhap gia tri cua nut con: ");
		int v; scanf("%d", &v);

		printf("Nhap vi tri can them (L -> left) (R -> right): ");
		char c; scanf(" %c", &c);
	
		if ((*root) == NULL) {
			(*root) = makeNode(u);
			insertRoot(root, u, v, c);
		} else insertNode(root, u, v, c);
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
	printf("Previous Order: ");
	preOrder(root);

	printf("So nut la tren cay: %d\n", countLeaft(root));

	printf("Nhap gia tri nut can tim: ");
	int x; scanf("%d", &x);
	Node *foundNode = findNode(root, x);

	if (foundNode) printf("Tim thay nut: %d\n", foundNode->data);
	else printf("Khong tim thay\n");

	freeTree(root);

	return 0;
}