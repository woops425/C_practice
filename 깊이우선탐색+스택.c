#include <stdio.h>
#include <stdlib.h>

// 최대 정점의 수
#define MAX_VERTICES 7

#define FALSE 0
#define TRUE 1

typedef int element;							// 스택 원소(element)의 자료형을 int로 정의 

// 노드(엣지) 구조체
typedef struct Node {
	int vertex;
	struct Node* next;
} Node;

// 그래프 구조체
typedef struct Graph {
	int numV;									// 그래프의 정점 개수
	Node* adjList[MAX_VERTICES];				// 그래프 정점에 대한 헤드 포인터 배열
	int visited[MAX_VERTICES];					// 정점에 대한 방문 표시를 위한 배열
} Graph;

// 스택(연결리스트) 구조체
typedef struct  Stack {
	element data;
	struct Stack* next;
} Stack;

// 스택 초기화 함수
void initializeStack(Stack** top) {
	*top = NULL;
}

// 스택이 공백 상태인지 확인하는 함수
int isEmpty(Stack* top) {  // top이 바뀌기 때문에 이중 포인터 활용
	return top == NULL;   // 기존 스택은 top이 -1
}

// 스택에 원소를 삽입하는 함수
void push(Stack** top, element item) {
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	temp->data = item;
	temp->next = *top;
	*top = temp;
}

// 스택에서 원소를 삭제하는 함수
element pop(Stack** top) {
	if (isEmpty(*top)) {
		fprintf(stderr, "Stack is empty!\n");
		return -1;
	}
	Stack* temp = *top;
	element item = temp->data;
	*top = temp->next;
	free(temp);
	return item;
}

// 스택의 상단 원소를 반환하는 함수
element peek(Stack* top) {
	if (isEmpty(top)) {
		fprintf(stderr, "Stack is empty!\n");
		return -1;
	}
	return top->data;
}

// 스택의 원소를 출력하는 함수
void printStack(Stack* top) {
	printf("\n STACK [ ");
	while (top != NULL) {
		printf("%d ", top->data);
		top = top->next;
	}
	printf("] ");
}

// 인접 리스트
// 공백 그래프를 생성하는 연산
void createGraph(Graph* g, int numV) {
	int i;
	g->numV = numV;							
	for (i = 0; i < numV; i++) {
		g->adjList[i] = NULL;					// 그래프의 정점에 대한 헤드 포인터 배열을 NULL로 초기화
		g->visited[i] = FALSE;					// 그래프의 정점에 대한 배열 visited를 FALSE로 초기화 추가
	}
}

// 그래프 g에 간선 (u,v)를 삽입하는 연산-가장 처음에 삽입하는 방법
void insertEdge(Graph* g, int u, int v) {
	Node* node;

	// 간선(u,v)를 삽입하기 위해 정점 u와 정점 v가 현재 그래프에 있는지 확인
	if (u >= g->numV || v >= g->numV) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	node = (Node*)malloc(sizeof(Node));
	node->vertex = v;
	node->next = g->adjList[u];					// 삽입 간선에 대한 노드를 리스트의 첫 번째 노드로 연결
	g->adjList[u] = node;
}

// 그래프 g의 각 정점에 대한 인접 리스트를 출력하는 연산
void printGraph(Graph* g) {
	for (int i = 0; i < g->numV; i++) {
		printf("\n\t\t정점 %c의 인접 리스트: ", i + 65);
		//printf("\n\t\t정점 %d의 인접 리스트: ", i);
		Node* temp = g->adjList[i];
		while (temp) {
			printf("%c -> ", temp->vertex + 65); // 정점 0~3을 A~D로 출력
			//printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

// DFS - 수정 0508
// 그래프 g에서 정점 v에 대한 깊이 우선 탐색 연산
void DFS_adjList(Graph* g, int v) {
	Stack* s = NULL;
	initializeStack(&s);
	push(&s, v);                                // 깊이 우선 탐색을 시작하는 정점 v를 스택에 push
	g->visited[v] = TRUE;                       // 정점 v를 방문했으므로 해당 배열 값을 TRUE로 설정
	printf("방문: %c\n", v + 65);               // 방문한 정점을 출력

	while (!isEmpty(s)) {
		int allVisited = TRUE;                  // 모든 인접 정점이 방문되었는지 확인하는 플래그
		v = peek(s);                            // 스택의 최상위 정점을 확인
		Node* w = g->adjList[v];                // 현재 정점의 인접 리스트 가져오기

		while (w) {
			if (!g->visited[w->vertex]) {
				push(&s, w->vertex);            // 방문하지 않은 인접 정점을 스택에 push
				g->visited[w->vertex] = TRUE;   // 정점 w에 대한 방문 표시
				printf("방문: %c\n", w->vertex + 65);  // 방문한 정점을 출력
				allVisited = FALSE;             // 아직 방문하지 않은 인접 정점이 있음
				break;                          // 새 정점을 방문했으므로 내부 루프 중단
			}
			w = w->next;                        // 다음 인접 정점으로 이동
		}

		if (allVisited) {
			pop(&s);                            // 모든 인접 정점을 방문했으면 스택에서 현재 정점 제거
		}
	}
}

int main(void) {
	int i;
	Graph G9;
	createGraph(&G9, MAX_VERTICES);

	insertEdge(&G9, 0, 2);
	insertEdge(&G9, 0, 1);
	insertEdge(&G9, 1, 4);
	insertEdge(&G9, 1, 3);
	insertEdge(&G9, 1, 0);
	insertEdge(&G9, 2, 4);
	insertEdge(&G9, 2, 0);
	insertEdge(&G9, 3, 6);
	insertEdge(&G9, 3, 1);
	insertEdge(&G9, 4, 6);
	insertEdge(&G9, 4, 2);
	insertEdge(&G9, 4, 1);
	insertEdge(&G9, 5, 6);
	insertEdge(&G9, 6, 5);
	insertEdge(&G9, 6, 4);
	insertEdge(&G9, 6, 3);

	printf("\n G9의 인접 리스트 ");
	printGraph(&G9);							//G9의 인접 리스트를 확인용으로 출력

	printf("\n\n///////////////\n\n���� �켱 Ž�� >> ");
	DFS_adjList(&G9, 0);						// 0번 정점인 정점 A에서 깊이 우선 탐색 시작
	getchar();   return 0;
}