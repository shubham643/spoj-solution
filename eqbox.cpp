#include<bits/stdc++.h>
using namespace std;

int main()
{
	double t;
	scanf("%lf",&t);
	while(t--)
	{
		double a,b,c,d;
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		if(a>b)
		{
			double temp=a;
			a=b;
			b=temp;
		}
		if(c>d)
		{
			double temp=c;
			c=d;
			d=temp;
		}
		double temp=sqrt(a*a+b*b);
	//	cout<<temp<<" ";
		temp-=c*b/a;
	//	cout<<temp<<" ";
		if((d<temp&&c<a)||(c<a&&d<b))
			printf("Escape is possible.\n");
		else
			printf("Box cannot be dropped.\n");
	}
	return 0;
}