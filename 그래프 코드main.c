#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5  // �ִ� ������ ��. ���� X

// �׷��� ����ü
typedef struct Graph {
    int numV;                                   // ������ ��
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];  // ���� ���
} Graph;

// �׷��� �ʱ�ȭ
void graphInit(Graph* g, int numV) {
    g->numV = numV;
    for (int i = 0; i < numV; i++) {
        for (int j = 0; j < numV; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// ���� �߰�
void addEdge(Graph* g, int from, int to) {
    g->adjMatrix[from][to] = 1;  // ���� �׷���
    //g->adjMatrix[to][from] = 1;  // ������ �׷���
}

// �׷��� ���
void printGraph(Graph* g) {
    for (int i = 0; i < g->numV; i++) {
        for (int j = 0; j < g->numV; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    graphInit(&g, MAX_VERTICES);

    // ���� �߰�
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 4);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);

    // �׷��� ���
    printGraph(&g);

    return 0;
}
