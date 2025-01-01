#include <stdio.h>

// 퀵 정렬 함수
void quickSort(int arr[], int low, int high) {
    if (low < high) { // 배열의 크기가 1 이상일 때만 수행
        int pivot = arr[(low + high) / 2];  // 피벗을 배열의 중간 지점 원소로 설정
        int i = low;  // 피벗을 기준으로 왼쪽부터 탐색할 인덱스
        int j = high;  // 피벗을 기준으로 오른쪽부터 탐색할 인덱스
        int temp;

        // 분할 과정
        while (i <= j) {
            // 피벗을 기준으로 왼쪽에서 피벗보다 큰 값을 찾음
            while (arr[i] < pivot) i++;
            // 피벗을 기준으로 오른쪽에서 피벗보다 작은 값을 찾음
            while (arr[j] > pivot) j--;

            // 찾은 값들을 교환
            if (i <= j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        // 분할된 부분 배열에 대해 재귀적으로 퀵 정렬 수행
        if (low < j) quickSort(arr, low, j); // 왼쪽 부분 배열에 대해 퀵 정렬 수행
        if (i < high) quickSort(arr, i, high); // 오른쪽 부분 배열에 대해 퀵 정렬 수행
    }
}

int main()
{
    int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };   // 정렬할 원소 
    int size = sizeof(list) / sizeof(list[0]);
    printf("정렬할 원소: \n");
    for (i = 0; i < size; i++)  printf("%d ", list[i]); // 정렬 전의 원소 출력
    printf("\n\n<<<<<<<<<< 퀵 정렬 수행 >>>>>>>>>>\n");
    quickSort(list, 0, size - 1);  // 퀵 정렬 함수 호출
    for (i = 0; i < size; i++)  printf("%d ", list[i]); // 정렬 후의 원소 출력
    printf("\n");
    return 0;
}