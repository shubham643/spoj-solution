#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	for(t=1;t<=10;t++)
	{
		int len;
		scanf("%d",&len);
		char s[len+1];
		int a[len+1];
		scanf("%s",s);
		int i,level=0;
		for(i=0;i<len;i++)
		{
			if(s[i]=='(')
				a[i]=level+1;
			else
				a[i]=level-1;
		}
		int minm=999999;
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int m;
			scanf("%d",&m);
			if(m>0)
			{
				m--;
				if(s[m]==')')
					s[m]='(';
				else
					s[m]=')';
				if(m<minm)
					minm=m;
			}
			else
			{
				if(minm==999999){
					i=0;
					level=0;
				}
				else{
					i=minm;
					level=a[minm-1];
				}
				for(i;i<len;i++)
				{
					if(s[i]==')'){
						a[i]=level-1;
						level--;
					}
					else{
						a[i]=level+1;
						level++;
					}
					if(a[i]<0)
						break;
				}
				if(i==len&&a[len-1]==0)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}