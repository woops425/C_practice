#include <stdio.h>

void toBinary(int n) {
    if (n == 0) // 재귀함수 종료 조건
        return;

    toBinary(n / 2); // n을 2로 나눈 몫에 대해 재귀 호출

    // n을 2로 나눈 나머지를 출력 (역순으로 출력되도록)
    printf("%d", n % 2);


    // if(n == 1)
    //     printf("1");
    // else {
    //     int num = n % 2;
    //     toBinary(n / 2);
    //     printf("%d", num);
    // }
}


int main(void) {
    int num;

    printf("Please enter a number: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("0\n");
    } 
    else {
        printf("2진수 변환 : ");
        toBinary(num);
    }

    return 0;
}