#include<bits/stdc++.h>
using namespace std;

long abs(long a,long b)
{
	a=a<0?-a:a;
	b=b<0?-b:b;
	return max(b-a,a-b);
}

void findit(long n)
{
		long res=1,temp;
		long i=0;
		if(n<0)
			temp=-n;
		else
			temp=n;
		if(temp&1){
			if(n<0)
				temp++;
			else
				temp--;
		}
		while(res<temp)
		{
			i++;
			res<<=1;
		}
		if((i&1 && n>0)||((i%2==0)&&n<0))
		{
	//		cout<<"here";
			i++;
			res<<=1;
		}
		if(n<0)
			res=-res;
		printf("1");
		i--;
		while(i>0)
		{
		    long temp=1;
		    temp<<=i;
	//	    cout<<" "<<temp<<" ";
			if(i&1)
				temp=-temp;
			i--;
			if(abs(res+temp,n)<=abs(res,n))
			{
				printf("1");
				res+=temp;
			}
			else
				printf("0");
		}
		if(n<0)
		{
			if((-n)&1)
				printf("1");
			else
				printf("0");
		}
		else
		{
			if(n&1)
				printf("1");
			else
				printf("0");
		}
}

int main()
{
	long n;
	long t;
//	cin>>t;
//	while(t--){
	scanf("%ld",&n);
	long i;
	long res=1;
	if(n==0)
		cout<<"0";
	else if(n==1)
		cout<<"1";
	else
		findit(n);
	//cout<<endl<<endl;

	//}
	return 0;
}