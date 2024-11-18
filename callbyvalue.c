# include <stdio.h>

void Swap(int * ptr1, int * ptr2);

int main(void) {
    int num1 = 10;
    int num2 = 20;
    printf("num1 num2 : %d %d \n", num1, num2);

    Swap(&num1, &num2);
    printf("num1 num2 : %d %d \n", num1, num2);

    return 0;
}

void Swap(int * ptr1, int * ptr2) {
    int temp = *ptr1; // temp에 ptr1이 가리키는 주소의 값을 저장
    *ptr1 = *ptr2;  // ptr1이 가리키는 주소의 값을 ptr2가 가리키고 있는 주소의 값으로 바꿈 10 -> 20
    *ptr2 = temp;   // ptr2가 가리키고 있는 주소의 값을 temp에 저장되어 있던 값으로 바꿈 20 -> 10
    printf("n1 n2 : %d %d \n", *ptr1, *ptr2);
}
