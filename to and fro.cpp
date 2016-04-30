#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

void printit(char *s,int i,int len,int col)
{
    if(i<len)
    {
        printf("%c",s[i]);
        int rem=i%col;
        printit(s,i+col*2-1-2*rem,len,col);
    }
    else
        return;
}

int main()
{
    while(1)
    {
        int col;
        scanf("%d",&col);
        if(col==0)
            break;
        char s[500];
        scanf("%s",s);
        int len=strlen(s);
        int i;
        for(i=0;i<col;i++)
            printit(s,i,len,col);
        printf("\n");
    }
    return 0;
}
