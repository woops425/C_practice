#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* llink;
    struct Node* rlink;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("메모리 할당 에러\n");
        return NULL;
    }
    newNode->data = data;
    newNode->rlink = NULL;
    newNode->llink = NULL;
    return newNode;
}

void insertNode(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (!newNode) return;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (position == 1) {
        newNode->rlink = *head;
        (*head)->llink = newNode;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int count = 1;

    while (count < position -1 && temp->rlink != NULL) {  // 삽입할 노드 바로 앞을 가리키고있음
        temp = temp->rlink;
        count++;
    }

    newNode->rlink = temp->rlink;
    if (temp->rlink != NULL) {
        temp->rlink->llink = newNode;
    }
    temp->rlink = newNode;
    newNode->llink = temp;
}

void deleteNode(Node** head, int key) {
    if (*head == NULL) return;

    Node* temp = *head;
    while (temp != NULL && temp->data != key) {     // 삭제할 노드를 가리키고 있음
        temp = temp->rlink;
    }

    if (temp == NULL) return;       // 키 못찾음

    if (temp->llink != NULL) {      //  첫번째 노드가 아닐 경우
        temp->llink->rlink = temp->rlink;
    }
    else {
        *head = temp->rlink;
    }

    if (temp->rlink != NULL) {      // 마지막 노드가 아닐 경우
        temp->rlink->llink = temp->llink;
    }

    free(temp);
}

void printList(Node* head) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->rlink;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    insertNode(&head, 10, 1);
    insertNode(&head, 20, 2);
    insertNode(&head, 30, 3);
    insertNode(&head, 40, 4);
    printList(head);

    deleteNode(&head, 30);
    printList(head);
    
    insertNode(&head, 100, 3);
    printList(head);

    return 0;
}