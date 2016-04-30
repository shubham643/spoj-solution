#include<bits/stdc++.h>
using namespace std;

class op{
public:
	bool operator()(const int &a,const int &b)
	{
		return a>b;
	}
};

int a[1000001];

set<int,op> s;

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int k;
	scanf("%d",&k);
	for(i=0;i<k;i++)
		s.insert(a[i]);
	set<int,op>::iterator ii;
	ii=s.begin();
	printf("%d ",*ii);
	for(i;i<n;i++)
	{
		s.insert(a[i]);
		ii=s.find(a[i-k]);
		if(ii!=s.end())
			s.erase(ii);
		ii=s.begin();
		printf("%d ",*ii);
	}
	return 0;
}