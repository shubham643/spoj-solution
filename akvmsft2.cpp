#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		multiset<int> s;
		int n,total=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int val;
			scanf("%d",&val);
			s.insert(val);
			total+=val;
		}
		if(total%n!=0)
			printf("-1\n");
		else
		{
			multiset<int>::iterator ii;
			multiset<int>::reverse_iterator jj;
			ii=s.begin();
			jj=s.rbegin();
			int c=0;
			int l=*ii;
			int r=*jj;
			cout<<l<<" "<<r;
			while(l!=r)
			{
				cout<<l<<" "<<r<<" ";
				if((l%2==0)&&(r%2==0))
				{
					int temp=(l+r)/2;
					s.erase(ii);
					s.erase(jj.base());
					s.insert(temp);
					s.insert(temp);
					c++;
				}
				else if((l%2==1) && (r%2==1))
				{
					int temp=(l+r)/2;
					s.erase(ii);
					s.erase(jj.base());
					s.insert(temp);
					s.insert(temp);
					c++;	
				}
				else
				{
					c=-1;
					break;
				}
				ii=s.begin();
				jj=s.rbegin();
				l=*ii;
				r=*jj;
			}
			printf("%d\n",c);
		}
	}
	return 0;
}