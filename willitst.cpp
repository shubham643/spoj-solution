#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	scanf("%lld",&n);
	if(n==0||n==1)
		cout<<"TAK";
	long long a=2;
	while(a<n)
		a=a<<1;
	if(a==n)
		printf("TAK");
	else
		printf("NIE");
	return 0;
}