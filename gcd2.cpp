#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int firstmodulo(int n,char *s)
{
	int i=0,len=strlen(s),count=0;
	int temp=n;
	while(temp)
	{
		count++;
		temp/=10;
	}
	i=i+count-1;
	int j;
	if(i>len-1)
		j=len-1;
	else
		j=i;
	temp=0;
	int c=j;
	for(j;j>=0;j--)
	{
		temp=temp+(s[j]-'0')*pow(10,c-j);
	}
	int mod=temp%n;
	i++;
	while(i<len)
	{
		mod=((mod*10)+(s[i]-'0'))%n;
		i++;
	}
	return mod;
}

int findgcd(int a,int b)
{
	int i;
	while(b)
	{
		int temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char s[1000];
		scanf("%s",s);
		if(n==0)
			{
				printf("%s\n",s);
				continue;
			}		
		int first=firstmodulo(n,s);
		int gcd=findgcd(n,first);
		printf("%d\n",gcd);
	}
	return 0;
}