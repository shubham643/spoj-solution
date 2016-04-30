#include<bits/stdc++.h>
using namespace std;

int abs(int t)
{
	return t<0?-t:t;
}

int main()
{
	int i;
	int sum=0,a[10];
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
	{
		if(abs(sum-100)<abs(sum+a[i]-100))
			break;
		else
			sum+=a[i];
	}
	printf("%d",sum);
}