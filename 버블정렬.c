# include <stdio.h>

// 버블 정렬 함수
void bubbleSort(int arr[], int size) {
    int i, j, t, temp;
    // 배열을 순회하면서 정렬을 수행하는 반복문
    for (i = 0; i < size - 1; i++) {
        printf("\n %d단계>>", i + 1);  // 현재 단계 출력
        // 한 단계가 끝날 때마다 가장 큰 원소가 제자리를 찾아가므로 그만큼 순회를 줄여줌
        for (j = 0; j < size - 1 - i; j++) {
            // 현재 원소와 다음 원소를 비교하여 정렬
            if (arr[j] > arr[j + 1]) {
                // 두 원소의 위치를 바꿔줌
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            // 정렬 상태 출력
            printf("\n\t");
            for (t = 0; t < size; t++) {
                printf("%3d ", arr[t]);
            }
        }
    }
}

int main(void) {
    int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 }; // 정렬할 원소
    int size = sizeof(list) / sizeof(list[0]);
    printf("\n정렬할 원소 : ");
    for (i = 0; i < size; i++) printf("%d ", list[i]);  // 정렬 전의 원소 출력
    printf("\n\n<<<<<<<<<<<< 버블 정렬 수행 >>>>>>>>>>>>>>>>\n");
    bubbleSort(list, size);      // 버블 정렬 함수 호출

    return 0;
}