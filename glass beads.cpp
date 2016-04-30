#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int save=0;
		string s,b,c;
		cin>>s;
		int len=s.length();
		char temp[len+1];
		int i=0,k,j;
		save=0;
		for(i=1;i<len;i++)
		{
			if(s[i]<s[save])
				save=i;
			else if(s[i]==s[save])
			{
				k=save;
				j=i;
				int count;
				bool tempt=false;
				for(count=0;count<len;count++)
				{
		//			cout<<save<<" "<<j;
					int p=save+count;
					if(p>=len)
						p-=len;
					int q=j+count;
					if(q>=len)
						q-=len;
					if(s[p]>s[q]){
						tempt=true;
						break;
					}
					else if(s[q]>s[p]){
						tempt=false;
						break;
					}
				}
				if(tempt)
					save=j;
			}
		}
		printf("%d\n",save+1);
	}
	return 0;
}