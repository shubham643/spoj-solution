#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,temp;
		scanf("%lld%lld",&n,&temp);
		if(temp==0)
			cout<<"Airborne wins."<<endl;
		else
			cout<<"Pagfloyd wins."<<endl;
	}
	return 0;
}