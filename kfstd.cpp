#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int q;
		scanf("%d",&q);
		multiset<int> s;
		while(q--)
		{
			int k,x;
			scanf("%d%d",&k,&x);
			if(k==1)
				s.insert(x);
			else if(k==2)
				s.erase(s.find(x));
			else if(k==3)
			{
				multiset<int>::iterator ii=s.begin();
				advance(ii,x-1);

			/*	for(ii=s.begin();ii!=s.end();ii++)
				{
					if(x==1)
						break;
					x--;
				}
			*/	printf("%d\n",*ii);
			}
			else
			{
				int c=0;
				multiset<int>::iterator ii;
				for(ii=s.begin();ii!=s.end();ii++)
				{
					if(x==*ii)
						break;
					c++;
				}
				printf("%d\n",c+1);
			}
		}
	}
}