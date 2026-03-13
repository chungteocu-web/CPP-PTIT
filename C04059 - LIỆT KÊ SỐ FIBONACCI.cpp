#include <iostream>
#include <cmath>
using namespace std;
long long fi[93] = {};
void fibo()
{
    fi[0] = 1;
    long long fn1 = 0, fn2 = 1, fn;
    for (int i = 1; i <=92; i++)
    {
        fn = fn1 + fn2;
        fi[i] = fn;
        fn1 = fn2;
        fn2 = fn;
    }
}
