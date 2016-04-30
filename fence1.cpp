#include<bits/stdc++.h>
#define PI 3.14159265
using namespace std;

int main()
{	
	while(1)
	{
		double n;
		cin>>n;
		if(n==0)
			break;
		double temp=n*n*1.00/(2*PI);
		printf("%.2lf\n",temp);
	}
	return 0;
}