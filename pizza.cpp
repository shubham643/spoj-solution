#include<bits/stdc++.h>
using namespace std;

int a[4];

int main()
{
	int n;
	scanf("%d",&n);
	a[0]=a[1]=a[2]=0;
	int i,count=0;
	char s[5];
	for(i=0;i<n;i++)
	{
		cin>>s;
		if(s[0]=='3')
			a[2]++;
		else if(s[2]=='4')
			a[0]++;
		else
			a[1]++;
	}
	count+=1;
	count+=a[2];
	a[0]-=a[2];
	count+=a[1]/2;
	a[1]%=2;
	if(a[1]==1)
	{
		count++;
		a[0]-=2;
		if(a[0]>0)
		{
			count+=a[0]/4;
			a[0]/=4;
			count++;
		}
	}
	else
	{
		if(a[0]>0){
		count+=a[0]/4;
		a[0]%=4;
		if(a[0]>0)
			count++;
		}
	}
	printf("%d",count);
	return 0;
}