//20191770 이유진
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &n1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL };
TreeNode m4 = { 25, NULL, &m7 };
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;


int get_node_count(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	}
	return count;
}
int get_leaf_count(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL) {
			return 1;
		}
		else {
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
		}
	}
	return count;
}
//p290 Quiz 02
int get_nonleaf_count(TreeNode* t) {
	return get_node_count(t) - get_leaf_count(t);
}
int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL) {
		height = 1 + max(get_height(node->left), get_height(node->right));
	}
	return height;
}

int equal(TreeNode* t1, TreeNode* t2) {
	int ret = 0;
	if (t1 == NULL && t2 == NULL)
		ret = 1;
	else if (t1 != NULL && t2 != NULL && (t1->data == t2->data) && equal(t1->left, t2->left) && equal(t1->right, t2->right))
		ret = 1;

	return ret;
}
//p319 #16
// 비단말 노드 중 자식이 하나인 노드의 개수 반환 
int get_oneleaf_count(TreeNode* root) {
	if (root != NULL) {
		if ((root->left != NULL) && (root->right == NULL)) 
			return 1 + get_oneleaf_count(root->left);
		else 
			if ((root->left == NULL) && (root->right != NULL)) 
				return 1 + get_oneleaf_count(root->right);
			else return get_oneleaf_count(root->left) + get_oneleaf_count(root->right); 
	} 
	return 0; 
} 
// 비단말 노드 중 자식이 둘인 노드의 개수 반환 
int get_twoleaf_count(TreeNode* root) {
	if (root != NULL) {
		if (root->left != NULL && root->right != NULL)
			return 1 + get_twoleaf_count(root->left) + get_twoleaf_count(root->right);
		else 
			return get_twoleaf_count(root->left) + get_twoleaf_count(root->right); 
	}
	return 0; 
} 
//p319 #17
int get_max(TreeNode* node) {
	TreeNode* tmp = root;

	while (tmp->right != NULL) {
		tmp = tmp->right;
	}
	return tmp->data;
}
int get_min(TreeNode* node) {
	TreeNode* tmp = root;

	while (tmp->left != NULL) {
		tmp = tmp->left;
	}
	return tmp->data;
}
void preorder(TreeNode* root) {
	if (root == NULL) return;

	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}
//p319 #20
TreeNode* node_increase(TreeNode* root) {
	if (root != NULL) {
		root->data += 1;
		if (root->left != NULL)
			node_increase(root->left);
		if (root->right != NULL)
			node_increase(root->right);
	}
	return root;
}

TreeNode* copy(TreeNode* p) {
	TreeNode* newNode = NULL; // 루트가 될 노드
	TreeNode* l;                     // left가 될 노드
	TreeNode* r;                    // right가 될 노드

	if (p != NULL) {                   // 매개변수로 받은 트리가 null이 아니라면
		l = copy(p->left);           // 재귀함수를 이용하여 left와 right를 재귀적으로 복사하는 것
		r = copy(p->right);
		newNode = (TreeNode*)malloc(sizeof(TreeNode));

		newNode->right = r;      // 루트의 right로 위에서 복사한 r을 가져옴
		newNode->left = l;        // 루트의 left로 위에서 복사한 l을 가져옴
		newNode->data = p->data;  // 루트의 아이템으로 트리포인터의 아이템을 가져옴
	}
	return newNode;
}


int main(void)
{
	TreeNode* result[MAX_TREE_SIZE];
	TreeNode* clone;
	int i, num;
	printf("가)\n");
	printf("트리 root 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root));
	printf("트리 root2 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root2));

	printf("트리 root 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root));
	printf("트리 root2 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2));
	printf("트리 root 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root));
	printf("트리 root2 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2));
	printf("트리 root 에서 가장 큰 수는 %d.\n", get_max(root));
	printf("트리 root2 에서 가장 큰 수는 %d.\n", get_max(root2));
	printf("트리 root 에서 가장 작은 수는 %d.\n", get_min(root));
	printf("트리 root2 에서 가장 작은 수는 %d.\n", get_min(root2));
	printf("\n 나)\n");
	preorder(root);
	node_increase(root);
	printf("\n");
	preorder(root);
	printf("\n");
	printf("%s\n", equal(root, root) ? "같다" : "다르다");
	printf("%s\n", equal(root2, root2) ? "같다" : "다르다");
	printf("%s\n", equal(root, root2) ? "같다" : "다르다");
	printf("\n 다)\n");
	clone = copy(root);
	preorder(root);
	printf("\n");
	preorder(clone);
	printf("\n");
}