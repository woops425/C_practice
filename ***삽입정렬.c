# include <stdio.h>

// 삽입 정렬 함수
void insertionSort(int arr[], int size) {
    int i, j, t, temp;

    // 배열의 두 번째 원소부터 시작하여 삽입 정렬을 수행
    for (i = 1; i < size; i++) {
        temp = arr[i];  // 삽입할 현재 원소를 temp에 저장
        j = i;  // 현재 원소의 인덱스를 j에 저장
        // 현재 원소를 정렬된 부분에 삽입하는 과정
        while ((j > 0) && (arr[j - 1] > temp)) {
            arr[j] = arr[j - 1];  // 현재 원소보다 큰 값을 한 칸씩 뒤로 이동
            j = j - 1;  // j를 한 칸 앞으로 이동
        }
        arr[j] = temp;  // 삽입할 위치에 현재 원소를 삽입
        printf("\n %d단계 ; ", i);  // 현재 단계 출력
        for (t = 0; t < size; t++) printf("%3d ", arr[t]);  // 정렬 상태 출력
    }
}

int main(void) {
    int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };  // 정렬할 원소
    int size = sizeof(list) / sizeof(list[0]);  // list 배열의 원소 개수
    printf("\n정렬할 원소 : ");
    for (i = 0; i < size; i++) printf("%d ", list[i]);  // 정렬 전의 원소 출력
    printf("\n\n<<<<<<<<<<<< 삽입 정렬 수행 >>>>>>>>>>>>>>>>\n");
    insertionSort(list, size);  // 삽입 정렬 함수 호출

    return 0;
}