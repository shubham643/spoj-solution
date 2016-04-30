#include<bits/stdc++.h>
using namespace std;

int search(int val,int *a,int s,int e)
{
//	cout<<"hwew"<<val;
	if(e<s)
		return -1;
	int mid=(s+e)/2;
	if(a[mid]==val)
		return mid;
	if(a[mid]>val)
		return search(val,a,s,mid);
	else
		return search(val,a,mid+1,e);
}

int findit(int val,int *array2,int c2)
{
	int count=0;
	int pos=search(val,array2,0,c2);
	if(pos!=-1)
	{
	//	cout<<"inside";
		int i;
		i=pos;
		while(i>=0&&array2[i]==val)
			i--;
		count+=pos-i;
		i=pos+1;
		while(i<=c2&&array2[i]==val)
			i++;
		count+=i-pos-1;
		return count;
	}
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int array1[10000];
	int array2[10000];
	int c1,c2;
	c1=c2=-1;
	int i;
	int ans=0;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int j,k;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				array1[++c1]=arr[i]*arr[j]+arr[k];
				if(arr[i])
					array2[++c2]=arr[i]*(arr[j]+arr[k]);
			}
		}
	}

	sort(array1,array1+c1+1);
	sort(array2,array2+c2+1);

	i=0;
	while(i<=c1)
	{
		j=i;
		while(j<=c1&&array1[j]==array1[i])
			j++;
		ans+=(j-i)*findit(array1[i],array2,c2);
		i=j-1;
		i++;
	}
	printf("%d\n",ans);
	return 0;
}