# include <stdio.h>

int Factorial(int n) {
    if (n==0)
    {
        return 1;
    }
    else
        return n * Factorial(n-1);  
}

int main(void) {

    printf("1! = %d\n", Factorial(1));
    printf("2! = %d\n", Factorial(2));
    printf("5! = %d\n", Factorial(5));
    printf("9! = %d\n", Factorial(9));
    return 0;
}
