#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int t;
    while(1)
    {
        long long n;
        scanf("%lld",&n);
        if(n==0)
            break;
        printf("%lld\n",n*(n+1)*(2*n+1)/6);
    }
    return 0;
}
