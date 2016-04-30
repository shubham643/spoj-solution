/*input
4
1 4 3 2
5
2 3 4 5 1
0
*/

#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			return 0;
		int i;
		int a[n+1];
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
		{
			if(a[a[i]]!=i)
			{
				break;
			}
		}
		if(i!=n+1)
			printf("not ambiguous\n");
		else
			printf("ambiguous\n");
	}
	return 0;
}
