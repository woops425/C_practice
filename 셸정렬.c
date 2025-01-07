#include <stdio.h>

// 부분 배열을 간격에 따라 삽입 정렬하는 함수
void intervalSort(int a[], int begin, int end, int interval) {
    int i, j, item;
    // 간격(interval)만큼 떨어진 요소들을 삽입 정렬
    for (i = begin + interval; i <= end; i = i + interval) {
        item = a[i]; // 현재 요소를 저장
        //삽입할 위치를 찾기 위해 정렬된 부분 배열을 뒤로 이동
        for (j = i - interval; j >= begin && item < a[j]; j = j - interval)
        a[j + interval] = a[j];
        // 올바른 위치에 현재 요소를 삽입
        a[j + interval] = item;
    }
}

// 셸 정렬 함수
void shellSort(int a[], int size) {
    int i, interval;
    // 초기 간격 (interval)을 배열 크기의 절반으로 설정
    interval = size / 2;
    // 간격이 1보다 크거나 같은 동안 반복
    while (interval >= 1) {
        // 각 간격에 대해 부분 배열을 삽입 정렬
        for (i = 0; i < interval; i++)
            intervalSort(a, i, size - 1, interval);
        // 현재 간격과 정렬된 배열 상태를 출력
        printf("\n interval=%d >> ", interval);
        for (i = 0; i < size; i++)
            printf("%d ", a[i]);
        printf("\n");
        // 간격을 반으로 줄임
        interval = interval / 2;
    }
}