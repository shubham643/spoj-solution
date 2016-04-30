#include<bits/stdc++.h>
using namespace std;

int a[1000005];
string p,q;

int main()
{
	int n;
	scanf("%d",&n);
	cin.ignore();
	
	int i;
	for(i=0;i<n;i++)
		a[i]=0;
	getline(cin,p);
	getline(cin,q);
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		a[l]++;
		a[r+1]--;
	}
	int count=0;	
	for(i=0;i<1000000;i++)
	{
		count+=a[i];
		if(count&1)
		{
			char temp=p[i];
			p[i]=q[i];
			q[i]=temp;
		}
	}
	cout<<p<<endl<<q<<endl;
	return 0;
}