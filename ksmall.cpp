#include<bits/stdc++.h>
using namespace std;

unsigned long long arr[5000000],med[1000002];

unsigned long long findmedian(unsigned long long *a,unsigned long long r)
{
	sort(a,a+r);
	if(r%2==0)
		return a[r/2-1];
	return a[r/2];
}

unsigned long long partition(unsigned long long *a,unsigned long long l,unsigned long long r,unsigned long long median)
{
	unsigned long long i;
	unsigned long long pos;
	for(i=l;i<r;i++)
	{
		if(a[i]==median)
			break;
	}
	if(i!=r)
	{
		unsigned long long temp=a[i];
		a[i]=a[r];
		a[r]=temp;
	}
	i=l-1;
	unsigned long long j=l;
	for(j;j<r;j++)
	{
		if(a[j]<=median){
			i++;
			unsigned long long temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	i++;
	unsigned long long temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	return i;
}

unsigned long long kthsmallest(unsigned long long *a,unsigned long long l,unsigned long long r,unsigned long long k)
{
	if(k>0&&k<=r-l+1)
	{
		unsigned long long n=r-l+1;
		unsigned long long i,j;
		for(i=0;i<n/5;i++)
			med[i]=findmedian(a+l+i*5,5);
		if(i*5<n)
		{
			med[i]=findmedian(a+l+i*5,n%5);
			i++;
		}
		unsigned long long median= (i==1) ? med[i-1] : kthsmallest(med,0,i-1,i/2);
		unsigned long long pos=partition(a,l,r,median);
		if(pos-l==k-1)
			return a[pos];
		else if(pos-l>k-1)
			return kthsmallest(a,l,pos-1,k);
		else
			return kthsmallest(a,pos+1,r,k-pos+l-1);
	}
	else
		return INT_MAX;	
}

int main()
{
	unsigned long long p,q,mod,k;
	cin>>p>>q>>mod>>k;
	for( unsigned long long i=0 ; i<5000000 ; i++ )
	{
		p = 31014 * (p & 65535) + (p >> 16);
		q = 17508 * (q & 65535) + (q >> 16);
		arr[i] = ((p << 16) + q) % mod;
	}
	cout<<kthsmallest(arr,0,5000000-1,k);
}