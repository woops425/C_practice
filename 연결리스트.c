#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 노드 생성
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)) ;  // newNode 동적할당
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 맨 앞에 삽입
void prependNode(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head; // newNode의 next를 head로 변경
    *head = newNode; // head를 newNode로 변경
}

// 맨 뒤에 삽입
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* lastNode = *head;
    while (lastNode->next != NULL) {  // 리스트 순회
        lastNode = lastNode->next;    // 마지막 나올때까지 순회
    }
    lastNode->next = newNode;        // newNode를 마지막 노드의 next에 저장
}

// 중간에 삽입(인덱스 기준)
void insertNodeAtIndex(Node** head, int data, int index) {
    if (index == 0) {
        prependNode(head, data);   // 맨 앞에 삽입하는 경우
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = *head;
    for (int i = 0; i < index -1 && temp != NULL; ++i) {    // 주어진 index의 바로 앞 노드까지 이동
        temp = temp->next;
    }
    if (temp == NULL) {                     // 오류 발생 시
        printf("Index out of bounds.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;             // temp의 next 포인터를 newNode의 다음 노드로 설정
    temp->next = newNode;                   // temp의 next 포인터를 새 노드로 변경하여 연결
}

// 맨 앞의 노드 삭제
void deleteFrontNode(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;         // 삭제할 노드 보관하는 임시 주소
    *head = (*head)->next;      // 헤드 이동
    free(temp);                 // 노드 제거
}

// 맨 뒤의 노드 삭제
void deleteLastNode(Node** head) {
    if (*head == NULL) return;  // 비었을때
    if ((*head)->next == NULL) {
        free(*head);
        *head =NULL;
        return;
    }
    Node* secondLast = *head;
    while (secondLast->next->next != NULL) {        //[:-1]의 값 찾기 ([:-1]의 next의 next가 NULL : 마지막 노드 삭제?)
        secondLast = secondLast->next;
    }
    free(secondLast->next);
    secondLast->next = NULL;    // NULL로 변경
}

// 중간의 노드 삭제 (값 기준)
void deleteNodeWithValue(Node** head, int value) {
    if (*head == NULL) return;          // 비었을 때
    if ((*head)->data == value) {       // 삭제할 값이 첫번째(head)와 동일할 때 동일 성동일
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL && temp->next->data != value) {       // 삭제할 값과 일치하는 노드 앞까지
        temp = temp->next;
    }
    if (temp->next == NULL) {           // 못 찾은 경우
        printf("Node not found.\n");
        return;
    }
    Node* toDelete = temp->next;        // 삭제할 노드를 toDelete 포인터에 저장
    temp->next = temp->next->next;      // 삭제할 노드의 다음 노드를 temp의 다음 노드로 설정하여 리스트에서 노드를 제거
    free(toDelete);
}

// 노드 탐색
Node* search(Node* head, int value) {
    Node* temp = head; // 방문한 노드 주소를 저장하는 임시 장소
    while (temp != NULL) {
        if (temp->data == value) return temp;
        temp = temp->next;
    }
    return NULL;
}

// 노드 갯수 구하기
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 리스트 출력
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 메모리 해제
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // 맨 앞에 노드 삽입
    prependNode(&head, 3);
    prependNode(&head, 2);
    prependNode(&head, 1);

    // 맨 뒤에 노드 삽입
    appendNode(&head, 4);
    appendNode(&head, 5);

    // 중간에 노드 삽입 (3번째 위치에 10 삽입)
    insertNodeAtIndex(&head, 10, 2);

    printf("초기 리스트: ");
    printList(head);

    // 노드 탐색
    Node* found = search(head, 10);
    if (found != NULL) {
        printf("노드 %d 탐색 성공\n", found->data);
    }
    else {
        printf("노드 탐색 실패\n");
    }

    // 노드 삭제
    deleteFrontNode(&head);     // 맨 앞 노드 삭제
    deleteLastNode(&head);      // 맨 뒤 노드 삭제
    deleteNodeWithValue(&head, 10) ;    // 값이 10인 노드 삭제

    printf("삭제 후 리스트: ");
    printList(head);

    // 노드 갯수 구하기
    int count = countNodes(head);
    printf("노드의 총 갯수: %d\n", count);

    // 메모리 삭제
    freeList(head);

    return 0;
}