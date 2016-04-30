#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y&&x>=0&&y>=0)
        {
            if(x%2==0)
                printf("%d",2*x);
            else
                printf("%d",2*x-1);
            printf("\n");
        }
        else if(x==y+2&&y>=0)
        {
            if(x%2==0)
                printf("%d\n",2*x-2);
            else
                printf("%d\n",2*x-3);
        }
        else
            printf("No Number\n");
    }
    return 0;
}
