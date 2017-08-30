#include <stdio.h>
#include <stdlib.h>

int fib_yail(int n);

///page 65
int main65() {
    for (int i = 0; i < 10; ++i) {
        int res = fib_yail(i);
        printf("the %d value in fib seria is: %d\n", i, res);
    }
    //system("PAUSE");
    return 0;
}

int fib_yail(int n)
{
    int a = 1, b = 1;

    for (int i = 1; i < n; i++)
    {
        int tmp = a + b;
        a = b;
        b = tmp;
    }

    return a;

}
///page 65