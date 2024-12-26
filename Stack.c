// #include <stdio.h>

// void HanoiTower(int num, char from, char tmp, char to)
// {
//     if (num == 1)
//     {
//         printf("1번째 기둥 : %c -> %c \n", num, from, to);
//     }
//     else
//     {
//         HanoiTower(num-1, from, to, tmp);
//         printf("%c번째 기둥 : %c -> %c \n", num, from, to);
//         HanoiTower(num-1, tmp, from, to);
//     }
    
// }
// int main(void)
// {
//     HanoiTower(3, 'A', 'B', 'C');
//     return 0 ;
// }

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int top;
    
} Stack;

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, int data)
{
    if (isFull(s)) {
        printf("Stack is full!!\n");
    }
    else {
        s->top++;
        s->items[s->top] = data;
    }
}

int pop(Stack* s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!!\n");
        return -1;  //스택이 비어있을 경우의 예외 처리
    }
    else
    {
        int data = s->items[s->top];
        s->top--;
        return data;
    }
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!!\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

int main()
{
    Stack s;
    s.top = -1;
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    printf("(peek) 현재 Top 원소 : %d\n", peek(&s));
    printf("(pop) 제거된 원소 : %d\n", pop(&s));
    printf("(peek) 현재 Top 원소 : %d\n", peek(&s));
    printf("(pop) 제거된 원소 : %d\n", pop(&s));
    printf("(peek) 현재 Top 원소 : %d\n", peek(&s));

    return 0;
}