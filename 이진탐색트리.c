#include <stdio.h>
#include <stdlib.h>

// 노드 구조 정의 - 이중연결리스트로 구성
typedef struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

// 새로운 노드를 생성하는 함수
BinaryTreeNode* createNode(int data) {
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    node->data = data;
    node->left = node->right = NULL;  // 왼쪽, 오른쪽에 NULL값으로 초기화
    return node;
}

//  ***이진 탐색 트리에서 특정 값을 탐색하는 함수
BinaryTreeNode* searchNode(BinaryTreeNode* root, int data) {
    if (root == NULL || root->data == data) { // 현재 노드가 NULL이거나 현재 노드의 데이터가 찾고자 하는 데이터와 일치하면 해당 노드를 반환
        return root;
    }

    if (data < root->data) {    // 찾고자 하는 데이터가 현재 노드의 데이터보다 작으면 왼쪽 서브트리에서 재귀적으로 탐색
        return searchNode(root->left, data);
    }
    else {  // 찾고자 하는 데이터가 현재 노드의 데이터보다 크면 오른쪽 서브트리에서 재귀적으로 탐색
        return searchNode(root->right, data);
    }
}

//  ***이진 탐색 트리에 노드를 삽입하는 함수
BinaryTreeNode* insertNode(BinaryTreeNode* root, int data) {
    // 현재 노드가 NULL인 경우, 새로운 노드를 생성하여 반환
    if (root == NULL) {
        return createNode(data);   
        // 노드가 존재하지 않는 위치에 새로운 노드를 생성 // 재귀함수를 돌다가 root가 Null이 되었을 때(=탐색 실패) data를 집어넣어주는 부분
    }
    // 삽입할 데이터가 현재 노드의 데이터보다 작은 경우, 왼쪽 서브트리로 이동
    if (data < root->data) {  // data와 root의 data를 비교 : 탐색을 하기 위함 . data가 더 작으면 왼쪽으로 이동
        root->left = insertNode(root->left, data);   // 왼쪽 서브트리에 대해 재귀적으로 삽입 수행
        // root의 왼쪽으로 재귀.(이해하기 쉽게 왼쪽 이동이라 하였지만, root를 왼쪽에 해당하는 값으로 재설정 한 것임. ex)root가 8이었는데 왼쪽으로 이동해서 root가 3이 됨- 컴퓨팅 식 이해)
    }   // 자기 자신을 호출할 때 root의 left가 root가 되어서 호출   
     // 탐색 실패하여 data를 집어넣는 과정을 돌고 node를 생성하고 다시 여기로 돌아옴(5분 전으로 재귀)

    else if (data > root->data) {   // 삽입할 데이터가 현재 노드의 데이터보다 큰 경우, 오른쪽 서브트리로 이동
        root->right = insertNode(root->right, data);    // 오른쪽 서브트리에 대해 재귀적으로 삽입 수행
    }
    // 현재 노드를 반환 (재귀적으로 상위 노드에 연결)
    return root;
}

// 이진 탐색 트리에서 최소값을 찾는 함수
BinaryTreeNode* findMin(BinaryTreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

//  ***이진 탐색 트리에서 노드를 삭제하는 함수
BinaryTreeNode* deleteNode(BinaryTreeNode* root, int data) { // main에서 root와 data 값을 받음
 // 트리가 비어 있는 경우, NULL을 반환
    if (root == NULL) {
        return root;
    }
    // 삭제할 값이 현재 노드의 값보다 작은 경우, 왼쪽 서브트리에서 삭제를 시도
    if (data < root->data) { // 탐색 먼저 시작. 찾게되면 노드를 찾은 경우로 이동 | // 그 과정에서 Return temp를 하게 되면 다시 여기로 재귀
        root->left = deleteNode(root->left, data);
    }
    // 삭제할 값이 현재 노드의 값보다 큰 경우, 오른쪽 서브트리에서 삭제를 시도
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);    // root의 right에 temp를 넣어줘라.
    }
    // 삭제할 값을 찾은 경우
    else {
        // 노드를 찾은 경우 (자식 노드가 0 또는 1)
        if (root->left == NULL) { 
            BinaryTreeNode* temp = root->right;    // 현재 노드의 오른쪽 자식을 임시로 저장  // 삭제할 값을 temp에 잠시 보관. 
            free(root); // 현재 노드 삭제
            return temp;   //오른쪽 자식노드가 후계자가 되어 자리를 물려줌 // 오른쪽 자식을 반환 (재귀적으로 상위 노드에 연결)     // 다시 재귀 - 67열로 돌아감
        }
        else if (root->right == NULL) {
            BinaryTreeNode* temp = root->left;  // 현재 노드의 왼쪽 자식을 임시로 저장
            free(root); // 현재 노드 삭제
            return temp;   // 왼쪽 자식노드가 후계자가 되어 자리를 물려줌  // 왼쪽 자식을 반환 (재귀적으로 상위 노드에 연결)
        }

        // 자식이 두 개인 노드
        BinaryTreeNode* temp = findMin(root->right);    // root의 오른쪽 서브트리에 있는 노드들 중 가장 작은 값을 찾음
        root->data = temp->data;   // 찾은 값을 현재 노드에 복사   // 찾은 가장 작은 값을 root의 data에 집어넣음
        root->right = deleteNode(root->right, temp->data);      // 고아가 된 노드들을 끌어올림(가장 작은 값이 있던 곳의 temp에 고아들 집어넣음으로써)
    }       // 오른쪽 서브트리에서 가장 작은 값을 삭제

    return root;    // 갱신된 루트를 반환
}

// 중위 순회 함수
void inorderTraversal(BinaryTreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    BinaryTreeNode* root = NULL;
    root = insertNode(root, 8);
    insertNode(root, 3);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 4);
    insertNode(root, 10);
    insertNode(root, 14);
    insertNode(root, 11);
    insertNode(root, 16);

    printf("Inorder traversal of the BST:\n");
    inorderTraversal(root);
    printf("\n");

    // 특정 값을 탐색합니다
    int key = 11;
    BinaryTreeNode* searchResult = searchNode(root, key);
    if (searchResult != NULL) {
        printf("Found key %d in the tree.\n", key);
    }
    else {
        printf("Key %d not found in the tree.\n", key);
    }

    // 노드를 삭제합니다
    printf("Deleting node 10\n");
    root = deleteNode(root, 8);

    printf("Inorder traversal after deleting 10:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
