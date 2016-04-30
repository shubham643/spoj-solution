#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    while(1)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==0&&b==0&&c==0)
            break;
        else
        {
            if(b-a==c-b)
                printf("AP %d",b-a+c);
            else
                printf("GP %d",b/a*c);
            printf("\n");
        }
    }
    return 0;
}
