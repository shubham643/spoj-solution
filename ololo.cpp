#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	long n;
	scanf("%ld",&n);
	long val,res=0;
	while(n--)
	{
		scanf("%ld",&val);
		res=res^val;
	}
	printf("%ld",res);
	return 0;
}