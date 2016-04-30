#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		if(n==1)
			printf("R\n");
		else if(m==1)
			printf("D\n");
		else if(n&1&&m&1){
			if(n>m)
				printf("D\n");
			else
				printf("R\n");
		}
		else if(n&1){
			if(n>m)
				printf("U\n");
			else
				printf("R\n");
		}
		else if(m&1){
			if(n>m)
				printf("D\n");
			else
				printf("L\n");
		}
		else{
			if(n>m)
				printf("U\n");
			else
				printf("L\n");
		}
	}
	return 0;
}