#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

BinaryTreeNode* CreateBinaryTreeNode(void) {
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    node->data = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 노드 반환 함수
int GetNodeData(BinaryTreeNode* data) {
    return data->data;
}

void SetNodeData(BinaryTreeNode* node, int data) {
    node->data = data;
}

// 왼쪽 서브 트리 반환 함수
BinaryTreeNode* GetLeftSubTree(BinaryTreeNode* node) {
    return node->left;
}

// 오른쪽 서브 트리 반환 함수
BinaryTreeNode* GetRightSubTree(BinaryTreeNode* node) {
    return node->right;
}

// 재귀적으로 삭제
void RemoveSubTree(BinaryTreeNode* node) {
    if (node == NULL)
        return;
    
    RemoveSubTree(node->left);
    RemoveSubTree(node->right);
    free(node);
}

void SetLeftSubTree(BinaryTreeNode* parent, BinaryTreeNode* child) {
    RemoveSubTree(parent->left);        //기존 트리 삭제
    parent->left = child;
}

void SetRightSubTree(BinaryTreeNode* parent, BinaryTreeNode* child) {
    RemoveSubTree(parent->left);        //기존 트리 삭제
    parent->left = child;   
}

int main(void) {
    BinaryTreeNode* root = CreateBinaryTreeNode();
    BinaryTreeNode* leftNode = CreateBinaryTreeNode();
    BinaryTreeNode* rightNode = CreateBinaryTreeNode();
    BinaryTreeNode* leftleftNode = CreateBinaryTreeNode();

    SetNodeData(root, 1);
    SetNodeData(leftNode, 2);
    SetNodeData(rightNode, 3);
    SetNodeData(leftleftNode, 4);

    SetLeftSubTree(root, leftNode);
    SetRightSubTree(root, rightNode);
    SetLeftSubTree(leftNode, leftleftNode);

    printf("%d \n", GetNodeData(GetLeftSubTree(root)));
    printf("%d \n", GetNodeData(GetLeftSubTree(GetLeftSubTree(root))));

    RemoveSubTree(root);

    return 0;
}