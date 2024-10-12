# include <stdio.h>
int absoCompare(int num1, int num2); // 절댓값이 큰 정수 반환
int getAbsoValue(int num); // 전달인자의 절댓값 반환

int main(void) {
     int num1, num2;
    printf("두 개의 정수 입력 : ");
    scanf("%d %d", &num1, &num2);
    printf("%d와(과) %d 중 절댓값이 큰 정수 : %d \n", num1, num2, absoCompare(num1, num2));
    return 0;
}

int absoCompare(int num1, int num2) {
    if (getAbsoValue(num1) > getAbsoValue(num2))
    return num1;
    else
    return num2;
}
int getAbsoValue(int num) {
    if (num < 0)
    return num * (-1);
    else
    return num;
}