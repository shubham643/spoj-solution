#include<bits/stdc++.h>
using namespace std;

int main()
{
	double o=120.0/300.0*6,t=30.0/300.0*2.00*6,f=30.0/300.0*4.00*6,six=60.0/300.0*6,three=10.0/300.0*3.00*6,w=10.0/300.0*6,l=90.0/300.0*6;
	double temp=o+t+three+f+six;
	int test;
	scanf("%d",&test);
	while(test--)
	{
		double over;
		scanf("%lf",&over);
		double runs,wickets;
		runs=temp*over;
		printf("%.0lf/",runs);
		wickets=w*over;
		printf("%.0lf\n",wickets);
	}
	return 0;
}