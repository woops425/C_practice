# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void ClearLineReadBuffer(void);
void RemoveBSN(char str[]);
int main(void) {
    // int ch1, ch2;
    
    // ch1 = getchar(); // 문자 입력
    // ch2 = fgetc(stdin); // 엔터키 입력. 엔터키도 하나의 문자로 인식

    // putchar(ch1); // 문자 출력
    // fputc(ch2, stdout); // 엔터키 출력


    // int ch;
    
    // while(1) {  // ctrl + Z나 ctrl + D 입력 시 종료(EOF(End Of File))
    //     ch = getchar();
    //     if (ch==EOF)
    //     {
    //         break;
    //     }
    //     putchar(ch);
    // }


    // char * str = "Simple String";

    // printf("1. puts test ------ \n");
    // puts(str);
    // puts("So Simple String");

    // printf("2. fputs test ----- \n");
    // fputs(str, stdout);
    // printf("\n");
    // fputs("So Simple String", stdout);
    // printf("\n");

    // printf("3. end of main ----\n");


    // // fgets 함수 호출 예시
    // char str[7];
    // int i;

    // for (i = 0; i < 3; i++)
    // {
    //     fgets(str, sizeof(str), stdin);
    //     printf("Read %d : %s \n", i+1, str);
    // }


    // // 입력버퍼를 비우는 예제
    // char perID[7];
    // char name[10];

    // fputs("주민번호 앞 6자리 입력: ", stdout);
    // fgets(perID, sizeof(perID), stdin);
    // ClearLineReadBuffer(); // 입력버퍼 지우기

    // fputs("이름 입력 : ", stdout);
    // fgets(name, sizeof(name), stdin);
    // printf("주민번호 : %s\n", perID);
    // printf("이름 : %s\n", name);


    // 문자열 길이 반환 : strlen
    // char str[100];
    // printf("문자열 입력 : ");
    // fgets(str, sizeof(str), stdin);
    // printf("길이 : %lu, 내용 : %s \n", strlen(str), str);

    // RemoveBSN(str);
    // printf("길이 : %lu, 내용 : %s \n", strlen(str), str);


    // // 문자열 복사 함수 : strcpy, strncpy
    // char str1[20] = "1234567890";
    // char str2[20];
    // char str3[5];

    // puts("***** case 1 *****");
    // strcpy(str2, str1);
    // puts(str2);

    // puts("***** case 2 *****");
    // strncpy(str3, str1, sizeof(str3));
    // puts(str3);

    // puts("***** case 3 *****");
    // strncpy(str3, str1, sizeof(str3)-1);
    // // strncpy_s(str3, sizeof(str3), str1, 4);

    // str3[sizeof(str3)-1] = 0;
    // puts(str3);


    // // 문자열을 덧붙이는 함수 : strcat, strncat
    char str1[20] = "First~";
    char str2[20] = "Second";

    char str3[20] = "Simple num: ";
    char str4[20] = "1234567890";
    
    puts("***** case 1 *****");
    strcat(str1, str2);
    puts(str1);

    puts("***** case 2 *****");
    strncat(str3, str4, 7);
    puts(str3);


    // spirntf
    // char str1[5] = "123", str2[5] = "456", str3[10];
    // sprintf(str3, "%s%s", str1, str2);
    // printf("%s\n", str3);


    // 문자열 비교 함수 : strcmp, strncmp <- 두 문자열이 같으면 0 반환, 아니면 -1 반환
    // printf("%d\n", strcmp("ABCD", "ABCC")); // 0보다 큰 값이 출력(s1이 더 큼)
    // printf("%d\n", strcmp("ABCD", "ABCDE")); // 0보다 작은 값이 출력(s2가 더 큼)
    // printf("%d\n", strcmp("ABCD", "ABCD")); // 0 값이 출력(서로 같음(내용이 모두 같아야함))

    // char str1[20];
    // char str2[20];
    // printf("문자열 입력 1 : ");
    // scanf("%s", str1);
    // printf("문자열 입력 2 : ");
    // scanf("%s", str2);

    // if (!strcmp(str1, str2))
    // {
    //     puts("두 문자열은 완벽히 동일합니다.");
    // }
    // else {
    //     puts("두 문자열은 동일하지 않습니다.");
    //     if (!strncmp(str1, str2, 3))
    //     {
    //         puts("그러나 앞 세 글자는 동일합니다.");
    //     }
        
    // }


    // 변환함수 atoi(int), atil(long), atof(double)
    // char str[20];
    // printf("정수 입력 : ");
    // scanf("%s", str);
    // printf("%d \n", atoi(str)); // int형으로 변환
    // printf("실수 입력 : ");
    // scanf("%s", str);
    // printf("%g \n", atof(str));
    

    return 0;
}

void ClearLineReadBuffer(void) {
    while(getchar() != '\n');
}

void RemoveBSN(char str[]) {
    int len = strlen(str);
    str[len-1] = 0; // 0 은 Null문자를 뜻함. 마지막 위치 -1 위치를 null 위치로 바꿔줌으로써, fgets() 호출 시 마지막에 삽입되는 줄바꿈문자(\n)을 없애는 것
}