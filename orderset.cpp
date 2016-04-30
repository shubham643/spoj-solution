#include<bits/stdc++.h>
using namespace std;

int main()
{
	int q;
	set<int> s;
	set<int>::iterator ii,jj;
	scanf("%d",&q);
	while(q--)
	{
		char c;
		scanf("%c",&c);
		int n;
		scanf("%d",&n);
		switch(c)
		{
			case 'I': s.insert(n);
			break;
			case 'D': ii=s.find(n);
			if(ii!=s.end())
				s.erase(ii);
				break;
			case 'K': if(n>s.size())
						printf("invalid\n");
					else
					{ 
			            ii=s.begin();
			      
			            printf("%d\n",*(ii+n-1));
			        }
			        break;
			case 'C': jj=s.lower_bound(n);
			 			ii=s.begin();
			 			int temp;
			 			temp=jj-ii;
			 			printf("%d\n",temp);
		}
	}
	return 0;
}