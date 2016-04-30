#include<bits/stdc++.h>
using namespace std;

double a[100002];

int search(double n,int s,int e)
{
	if(e<s)
		return s;
	int mid=(s+e)/2;
	if(a[mid]==n)
		return mid;
	else if(a[mid]<n)
		return search(n,mid+1,e);
	else
		return search(n,s,mid-1);
}

int main()
{

	a[1]=0.5;
	int i=2;
	while(i<=100000)
	{
		a[i]=a[i-1]+1.0/(i+1);
		if(i>=100000||a[i]>=5.20)
			break;
		i++;
	}
	double n;
	while(1)
	{
		scanf("%lf",&n);
		if(n==0.0)
			return 0;
		int res=search(n,1,i);
		if(a[res]<n)
			cout<<res+1<<" card(s)";
		else
			cout<<res<<" card(s)";
		cout<<endl;
	}
	return 0;
}