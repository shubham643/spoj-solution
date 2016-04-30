#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s[10000];
	int c=1;
	while(1)
	{
		scanf("%s",s);
		if(s[0]=='-')
			break;
		int len=strlen(s);
		int i,level=0,count=0;
		for(i=0;i<len;i++)
		{
			if(s[i]=='}')
				level--;
			if(level<0)
			{
				level=1;
				count++;
			}
			if(s[i]=='{')
			{
				if(len-i-1>=level+1)
					level++;
				else
				{
					level--;
					count++;
				}
			}
		}
		printf("%d. %d\n",c,count);
		c++;
	}
	return 0;
}