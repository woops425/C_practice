#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("메모리 할당 에러\n");
        return NULL;
    }
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {        // 맨 뒤에 삽입
    Node* newNode = createNode(data);
    if (!newNode) return;

    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->link != *head) {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = *head;
    }
}

void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (!newNode) return;

    if (*head == NULL) {
        *head = newNode;
        newNode->link = newNode;
        return;
    }

    Node* temp = *head;
    int count = 1;

    // 첫 위치에 삽입
    if (position == 1) {
        while ( temp->link != *head) {      // 마지막 노드 찾기
            temp = temp->link;
        }
        newNode->link = *head;
        temp->link = newNode;
        *head = newNode;
        return;
    }

    // 삽입할 위치의 '이전'노드를 찾기
    for (int i = 1; i < position -1 && temp->link != *head; i++) {
        temp = temp->link;
    }
    newNode->link = temp->link;
    temp->link = newNode;
}

void deleteNode(Node** head, int key) {
    if (*head == NULL) return;

    Node* temp = *head, * prev = NULL;
    while (temp->data != key) {         // 키 가진 노드 찾기위해 순회
        prev = temp;
        temp = temp->link;
        if (temp == *head) return;      // 주어진 Key가 리스트에 없는 경우
    }

    if (temp->link == temp) {       // 리스트에 하나의 노드만 있는 경우
        *head = NULL;
    }
    else {
        if (temp == *head) {
            *head = (*head)->link;
        }
        prev->link = temp->link;
    }
    free(temp);
}


void printList(Node* head) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != head);
    printf("처음\n");
}

int main() {
    Node* head = NULL;
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);
    printList(head);

    deleteNode(&head, 30);
    printList(head);

    insertAtPosition(&head, 100, 3);
    printList(head);

    return 0;
}