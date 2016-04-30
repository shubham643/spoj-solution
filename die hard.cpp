#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==0||b==0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		a+=3;
		b+=2;
		int c=1;
		while(a>0&&b>0)
		{
			if(c&1)
			{
				if(a>14+b)
				{
					a-=20;
					b+=5;
				}
				else
				{
					a-=5;
					b-=10;
				}
				c++;
			}
			else
			{
				c++;
				a+=3;
				b+=2;
			}
		}
		cout<<c-1<<endl;
	}
	return 0;
}