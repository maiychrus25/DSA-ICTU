/**
 *    author:  tourist
 *    created: 2024.11.20 19:22:12
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node *left;
	Node *right;
} Node;

void init(Node **root) {
	(*root) = NULL;
}

Node *makeNode(int x) {
	Node *newNode = (Node*)malloc(sizeof (Node));	
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void insertNode(Node **root, int key) {
	if ((*root) == NULL) {
		(*root) = makeNode(key);
		return;
	}

	if (key < (*root)->data) {
		insertNode(&(*root)->left, key);
	} else {
		insertNode(&(*root)->right, key);
	}
}

void input(Node **root) {
	while (true) {
		printf("Nhap khoa cua nut (Nhap so am de thoat): ");
		int key; scanf("%d", &key);

		if (key < 0) return;
		insertNode(root, key);
	}
}

// hàm kiểm tra node lá
int isLeaf(Node *root) {
	return (root->left == NULL && root->right == NULL);
}

int countLeaf(Node *root) {
	if (root == NULL) return 0;
	if (isLeaf(root)) return 1;
	return countLeaf(root->left) + countLeaf(root->right);
}

void preOrder(Node *root) {
	if (root == NULL) return;
	printf("%d ", root->data);

	preOrder(root->left);
	preOrder(root->right);
}

int main() {
	Node *root;
	init(&root);

	input(&root);
	preOrder(root);

	printf("so nut la: %d", countLeaf(root));

	return 0;
}