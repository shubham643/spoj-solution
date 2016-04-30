#include<iostream>
#include<string.h>
#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a[1000005],check='e';
        scanf("%s",a);
        long i,len=strlen(a);
        for(i=len-1;i>len/2;i--)
        {
            if(a[len-i-1]>a[i])
                check='l';
            if(a[len-i-1]<a[i])
                check='s';
            a[i]=a[len-i-1];
        }
        if(len%2==0)
        {
            if(a[len/2-1]>a[len/2])
                check='l';
            else
                check='s';
            a[len/2]=a[len/2-1];
        }
        if(check=='s'||check=='e')
        {
            if(len%2==0&&a[len/2]!='9')
            {
                a[len/2]+=1;
                a[len/2-1]+=1;
            }
            else if(a[len/2]!='9'&&len%2==1)
                a[len/2]+=1;
            else if(a[len/2]=='9')
            {
                i=len/2+1;
                while(i<len&&a[i]=='9')
                {
                    a[i]=a[len-i-1]='0';
                    i++;
                }
                if(i!=len)
                {
                    a[i]+=1;
                    a[len-i-1]+=1;
                }
                else
                {
                    a[0]=a[len]='1';
                //    a[len-1]='0';
                    a[len+1]='\0';
                }
                if(len%2==0)
                {
                    a[len/2]=a[len/2-1]='0';
                    if(len==2)
                        a[0]='1';
                }
                else if(len!=1)
                    a[len/2]='0';
                else
                    a[len/2]='1';
            }
        }
        printf("%s\n",a);
    }
    return 0;
}
