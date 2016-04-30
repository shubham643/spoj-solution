#include<bits/stdc++.h>
using namespace std;


int s1[16000000],s2[16000000];

int main()
{
	int n;
	scanf("%d",&n);
	int a[4][n];
	int i,j=0;
	int idx=-1;
	for(i=0;i<n;i++)
		for(j=0;j<4;j++)
			scanf("%d",&a[j][i]);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			s1[++idx]=a[2][i]+a[3][j];
			s2[idx]=a[0][i]+a[1][j];
		}
	}

	sort(s1,s1+idx+1);
	sort(s2,s2+idx+1);

	long long count=0;
	i=0;
	j=idx;

	while(i<=idx&&j>=0)
	{
		long long sum=s1[i]+s2[j];
		int c1,c2;
		c1=i;
		while(c1<=idx&&s1[c1]==s1[i])
			c1++;
		c2=j;
		while(c2>=0&&s2[c2]==s2[j])
			c2--;
		if(sum==0){
			count+=((long long)(c1-i))*((long long)(j-c2));
			i=c1;
			j=c2;
		}
		else if(sum>0)
			j--;
		else
			i++;
	}

	printf("%lld",count);
	return 0;
}