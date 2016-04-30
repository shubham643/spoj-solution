#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		uint64_t n;
		cin>>n;
		uint64_t i;
		uint64_t sum=0,last=0;
		sum=n*1*(1+n*2-1)/2;
		sum+=(n*(n-1)*(2*n-1)/6+n*(n-1)/2)/2;
	//	cout<<"without"<<sum<<endl;
		uint64_t a=(n/2-1)*(n/2)*(2*(n/2-1)+1)/3;
		uint64_t b=(n/2)*(n/2-1)/2;
		if(n%2==0)
			sum+=a-b;
		else
			sum+=a+b;
		cout<<sum<<endl;
	}
	return 0;
}