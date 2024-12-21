# include <stdio.h>

int convCase(int ch) {
    // 아스키 코드에서의 모든 문자의 대소문자 간의 차의 크기는 같음
    const int diff = 'a' - 'A';
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + diff; // diff를 소문자 - 대문자로 했으니, 입력받은 ch에 diff만큼 다시 더해주면, 소문자로 변환됨
    }
    else if (ch >= 'a' && ch <= 'z') {
        return ch - diff;
    }
    else {
        return -1;
    }
}

int main(void) {
    int ch;
    printf("문자 입력 : ");
    ch = getchar(); // 문자 입력
    ch = convCase(ch); // 문자 변환(대문자 -> 소문자 or 소문자 -> 대문자)
    if (ch == -1) // 잘못된 입력
    {
        puts("잘못된 입력입니다.");
        return -1; // 프로그램 종료
    }
    putchar(ch); // 변환시킨 문자를 출력
    printf("\n");

    return 0;
}