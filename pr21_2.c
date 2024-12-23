# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int convToInt(int c) {
    // 아스키 코드에서의 모든 문자의 대소문자 간의 차의 크기는 같음
    const int diff = 1 - '1';
    return c + diff;
}
int main(void) {
    char str[100];
    int len;
    int sum = 0;

    printf("문자열 입력 : ");
    fgets(str, sizeof(str), stdin);
    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '1' && str[i] <= '9')
        {
            sum += convToInt(str[i]);
        }
    }
    printf("숫자의 총합 : %d\n", sum);
    
    

    return 0;
}