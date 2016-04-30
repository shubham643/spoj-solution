#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a[405];
        char pos[405];
        scanf("%s",a);
        stack<char> mystack;
        int i=0,k=-1;
        while(*(a+i))
        {
            char l=a[i];
 //           cout<<l;
            if(l>='a'&&l<='z')
                printf("%c",l);
            else if(l=='(')
                mystack.push(l);
            else if(l==')')
            {
                while(mystack.top()!='(')
                {
                    printf("%c",mystack.top());
                    mystack.pop();
                }
                mystack.pop();
            }
            else
                mystack.push(l);
            i++;
        }
        printf("\n");
    }
    return 0;
}
