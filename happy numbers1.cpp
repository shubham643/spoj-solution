#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	scanf("%lld",&n);
	bool flag[811];
	long long i,temp;
	for(i=0;i<811;i++)
		flag[i]=false;
	long long num=0;
	while(n)
	{
		temp=n%10;
		num+=temp*temp;
		n/=10;
	}
	if(num==1)
		printf("1");
	else
	{
		long long count=1,res=0;
		while(!flag[num]&&num!=1)
		{
	//		cout<<num<<" ";
			count++;
			res=0;
			temp=0;
			flag[num]=true;
			while(num)
			{
				temp=num%10;
				res+=temp*temp;
				num/=10;
			}	
	//		cout<<"res"<<res<<" ";
			num=res;
		}	
		if(num==1)
			printf("%d",count);
		else
			printf("-1");
	}
	return 0;
}