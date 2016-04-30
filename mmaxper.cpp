#include<bits/stdc++.h>
using namespace std;

int save[1000][1000],a[1000][1000];

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	save[0][0]=a[0][0];           // 0 means no rotation and length at top
	save[0][1]=a[0][1];
	for(i=1;i<n;i++)
	{
		save[i][0]=max(save[i-1][0]+a[i][0]+abs(a[i-1][1]-a[i][1]),save[i-1][1]+a[i][0]+abs(a[i-1][0]-a[i][1]));
		save[i][1]=max(save[i-1][0]+a[i][1]+abs(a[i-1][1]-a[i][0]),save[i-1][1]+a[i][1]+abs(a[i-1][0]-a[i][0]));
	}
	printf("%d",max(save[n-1][0],save[n-1][1]));
	return 0;
}