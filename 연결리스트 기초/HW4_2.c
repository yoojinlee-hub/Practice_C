//20191770 이유진
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(TreeNode* root) { // 중위 순회
	if (root) {
		inorder(root->left);// 왼쪽서브트리 순회
		printf("[%d] ", root->key); // 노드 방문
		inorder(root->right);// 오른쪽서브트리 순회
	}
}

//탐색(순환)
TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}
TreeNode* insert_node(TreeNode* root, int key)
{
	// 트리가 공백이면 새로운 노드를 반환한다.
	if (root == NULL) return new_node(key);
	// 그렇지 않으면 순환적으로 트리를 내려간다.
	if (key < root->key)
		root->left = insert_node(root->left, key);
	else if (key > root->key)
		root->right = insert_node(root->right, key);
	// 변경된 루트 포인터를 반환한다.
	return root;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL) // 맨 왼쪽 단말 노드를 찾으러 내려감
		current = current->left;
	return current;
}
// 삭제 함수
TreeNode* delete_node(TreeNode* root, int key)
{
	TreeNode* temp;
	if (root == NULL) return root;
	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (key < root->key)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	// 키가 루트와 같으면 이 노드를 삭제하면 됨
	else {
		// 첫 번째나 두 번째 경우
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// 세 번째 경우
		temp = min_value_node(root->right);
		// 중외 순회시 후계 노드를 복사한다.
		root->key = temp->key;
		// 중외 순회시 후계 노드를 삭제한다.
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
int get_max(TreeNode* root) {
	TreeNode* tmp = root;

	while (tmp->right != NULL) {
		tmp = tmp->right;
	}
	return tmp->key;
}
int get_min(TreeNode* root) {
	TreeNode* tmp = root;

	while (tmp->left != NULL) {
		tmp = tmp->left;
	}
	return tmp->key;
}
void preorder(TreeNode* root) {
	if (root == NULL) return;

	printf("%d ", root->key);
	preorder(root->left);
	preorder(root->right);
}
// 트리의 높이를 구하는 함수
int get_height(TreeNode* root) {
	if (root != NULL) {
		return 1 + max(get_height(root->right), get_height(root->left)); 
	} 
	return 0; 
}
// 노드의 개수를 구하는 함수 
int get_node_count(TreeNode* root) {
	if (root != NULL) {
		return 1 + get_node_count(root->left) + get_node_count(root->right); 
	} 
	return 0;
} 


int main(void) {
	TreeNode* root = NULL;
	char input = '0';

	while(1){
		int key = 0;
		
		printf("Enter i<nsert>,d<elete>,s<earch>,p<rint>,c<ount>,m<ax>,n<min>,q:");
		scanf("%c", &input);
		if (input == 'i') {
			printf("삽입할 key값 입력:");
			scanf("%d", &key);
			root = insert_node(root, key);
		}
		if (input == 'd') {
			printf("삭제할 key값 입력:");
			scanf("%d", &key);
			delete_node(root, key);
		}
		if (input == 's') {
			printf("탐색할 key값 입력:");
			scanf("%d", &key);
			TreeNode* a = search(root, key);
			if (a != NULL) printf("있음\n");
			else printf("없음\n");

		}
		if (input == 'p') {
			preorder(root);
			printf("\n");
		}	
		if (input == 'h') {
			printf("트리의 높이는 %d\n", get_height(root));
		}
		if (input == 'c') {
			printf("노드의 개수는 %d\n", get_node_count(root));
		}
		if (input == 'm') {
			printf("가장 큰 값은 %d\n", get_max(root));
		}
		if (input == 'n') {
			printf("가장 작은 값은 %d\n", get_min(root));
		}
		if (input == 'q')
			break;
		getchar();
	}

}