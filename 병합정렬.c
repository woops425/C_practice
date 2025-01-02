#include <stdio.h>
#define MAX 30 // 정렬된 원소를 저장할 배열의 최대 크기 정의

extern int size; // 배열 크기를 외부에서 참조할 수 있도록 extern 선언
int sorted[MAX]; // 원소를 병합하면서 정렬한 상태로 저장할 배열 선언

// 병합 함수: 두 부분집합을 병합하여 정렬된 하나의 배열로 만듦
void merge(int a[], int m, int middle, int n) {
    int i, j, k, t;
    i = m;              // 첫 번째 부분집합의 시작 위치 설정
    j = middle + 1;     // 두 번째 부분집합의 시작 위치 설정
    k = m;              // 배열 sorted에 정렬된 원소를 저장할 위치 설정

    // 두 부분집합을 비교하여 작은 원소를 sorted 배열에 저장
    while (i <= middle && j <= n) {
        if (a[i] <= a[j])
            sorted[k++] = a[i++];
        else
            sorted[k++] = a[j++];
    }

    // 첫 번째 부분집합이 먼저 끝났을 경우, 두 번째 부분집합의 나머지 원소를 sorted에 저장
    if (i > middle)
        for (t = j; t <= n; t++, k++)
            sorted[k] = a[t];
    // 두 번째 부분집합이 먼저 끝났을 경우, 첫 번째 부분집합의 나머지 원소를 sorted에 저장
    else
        for (t = i; t <= middle; t++, k++)
            sorted[k] = a[t];

    // 정렬된 원소를 원래 배열 a로 복사
    for (t = m; t <= n; t++)
        a[t] = sorted[t];

    // 현재 배열 상태 출력
    printf("\n 병합 정렬 >> ");
    for (t = 0; t < size; t++)
        printf("%4d ", a[t]);
}

// 병합 정렬 함수: 배열을 분할하고 병합하는 함수
void mergeSort(int a[], int m, int n) {
    int middle;
    if (m < n) {
        middle = (m + n) / 2;            // 중간 위치 계산
        mergeSort(a, m, middle);         // 앞 부분에 대한 분할 작업 수행
        mergeSort(a, middle + 1, n);     // 뒷 부분에 대한 분할 작업 수행
        merge(a, m, middle, n);          // 부분집합에 대하여 정렬과 병합 작업 수행 
    }
}

int size; // 배열의 크기를 저장할 전역 변수
int main(void) {
    int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 }; // 정렬할 배열 초기화
    size = sizeof(list) / sizeof(list[0]);  // list 배열의 원소 개수 계산

    // 정렬할 원소들을 출력
    printf("\n 정렬할 원소 >> ");
    for (i = 0; i < size; i++)
        printf("%4d ", list[i]);
    printf("\n\n<<<<<<<<<< 병합 정렬 수행 >>>>>>>>>>\n");

    // 병합 정렬 함수 호출
    mergeSort(list, 0, size - 1);

    // 최종 정렬된 배열 출력
    printf("\n 최종 정렬된 배열 >> ");
    for (i = 0; i < size; i++)
        printf("%4d ", list[i]);
    printf("\n");

    return 0;
}