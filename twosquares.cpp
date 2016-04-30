#include<bits/stdc++.h>
using namespace std;

long long save[10000001];

/*long long mul(long long a,long long b)
{
	long long ans=0;
	while(b)
	{
		if(b&1)
			ans+=a;
		a=a<<1;
		b=b>>1;
	}
	return ans;
}
*/
long long search(long long q,long long s,long long e)
{
	if(e<s)
		return s;
	long long mid=(s+e)/2;
	if(save[mid]==q)
		return mid;
	else if(save[mid]<q)
		return search(q,mid+1,e);
	else
		return search(q,s,mid-1);

}

int main()
{
	long long t;
	long long j=0;
	while(j<10000000)
	{
		save[j]=j*j;
	//	cout<<save[j]<<"  ";
		j++;
	}
	scanf("%lld",&t);
	while(t--)
	{
		bool res=false;
		long long q;
		scanf("%lld",&q);
		long long index=search(q,0,j-1);
	//	cout<<index;
	//	cout<<index<<" "<<save[index]<<"       ";
	//	if(save[index]<q)
	//		index++;
	//	cout<<index<<" "<<save[index]<<" ";
		long long check=save[index];
		check=check-(check/4)*2;
	//	cout<<check;
		while(check<=q)
		{
			cout<<index<<"  ";
	//		cout<<"inside";
			if(save[index]==q)
			{
				res=true;
				goto jump;
			}
			if(index&1)
			{
//				cout<<"odd";
				long long X=save[index]-save[index]/4*2-q;
				long long D=-8*X+4;
				long long temp=sqrt(D);
//				cout<<"temp:"<<temp<<" ";
				if(temp*temp==D&&(temp+2)/4<=index/2)
				{
					if(temp%2==0){
					res=true;
					goto jump;
					}
				}
			}
			else
			{
//				cout<<"even";
				long long m=sqrt((q+save[index]/4*2-save[index])/2);
		//		cout<<"m:"<<m<<" ";
				if(m*m==(q+save[index]/4*2-save[index])/2&&(q+save[index]/4*2-save[index])!=3&&m+1<=index/2)
				{
					cout<<"m:"<<m;
					res=true;
					goto jump;
				}
			}
			index++;
			check=save[index];
			check=check-(check/4)*2;
		}
		jump:
		if(res)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}