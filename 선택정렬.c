# include <stdio.h>

// 선택 정렬 함수
void SelectionSort(int arr[], int size) {
    int i, j, t, min, temp;

    // 배열을 순회하면서 최솟값을 찾아 앞으로 이동시키는 과정
    for (i = 0; i < size - 1; i++) {
        min = i; // 최솟값의 인덱스를 i로 초기화
        // i 이후의 원소들 중에서 최솟값을 찾음
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) min = j; // 최솟값의 인덱스를 업데이트
        }
        // 현재 위치와 최솟값을 교환
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        // 각 단계별 정렬 상태 출력
        printf("\n%d단계 : ", i + 1);
        for (t = 0; t < size; t++) printf("%3d ", arr[t]);
    }
}

int main(void) {
    int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 }; // 정렬할 원소
    int size = sizeof(list) / sizeof(list[0]);
    printf("\n정렬할 원소 : ");
    for (i = 0; i < size; i++) printf("%d ", list[i]); // 정렬 전의 원소 출력
    printf("\n\n<<<<<<<<<<<< 선택 정렬 수행 >>>>>>>>>>>>>>>>\n");
    SelectionSort(list, size);      // 선택 정렬 함수 호출

    return 0;
}