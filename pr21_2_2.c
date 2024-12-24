# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main(void) {
    char str1[20], str2[20], str3[40];
    printf("문자열 입력 : ");
    fgets(str1, sizeof(str1), stdin);
    str1[strlen(str1)-1] = 0;

    printf("문자열 입력 : ");
    fgets(str2, sizeof(str2), stdin);
    str2[strlen(str2)-1] = 0;

    strcpy(str3, str1);
    strncat(str3, str2, 6);
    // sprintf_s(str3, sizeof(str3), "%s%s", str1, str2);
    puts(str3);



    return 0;
}