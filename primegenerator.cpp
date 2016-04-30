#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int array[100001];
    long i;
    for(i=0;i<100001;i++)
        array[i]=0;
    while(t--)
    {
        long a,b,i,save;
        scanf("%ld%ld",&a,&b);
        long temp,k;
        for(temp=2;temp<=b;temp++)
        {
            if(temp<a)
            {
                save=temp;
                long rem=a/temp;
                if(a%temp==0)
                    temp=a;
                else
                    temp=(rem+1)*temp;
                while(temp<=b)
                {
                    array[temp-a]=1;
                    temp+=save;
                }
            }
            else
            {
                if(array[temp-a]==0)
                    printf("%ld\n",temp);
                save=temp;
                while(temp<=b)
                {
                    array[temp-a]=1;
                    temp+=save;
                }
            }
            temp=save;
            if(temp>=a)
                array[temp-a]=0;
        }
    }
    return 0;
}
