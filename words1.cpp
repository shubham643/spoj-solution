#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i,countsolo=0;
		int start[26];
		int ending[26];
		bool solo[26];
		for(i=0;i<26;i++)
			start[i]=ending[i]=solo[i]=0;
		for(i=0;i<n;i++)
		{
			char s[1005];
			scanf("%s",s);
			if(s[0]==s[strlen(s)-1]){
				countsolo++;
				solo[s[0]-'a']=true;
			}
			else
			{
				start[s[0]-'a']++;
				ending[s[strlen(s)-1]-'a']++;
			}
		}
		int count=0,total=0;
		for(i=0;i<26;i++)
		{
			if(!solo[i])
			{
				if(start[i]==ending[i]+1||start[i]+1==ending[i]){
					total+=min(start[i],ending[i]);
					count++;
				}
				else if(start[i]>ending[i]+1||start[i]+1<ending[i])
					count=3;
				else if(start[i]==ending[i])
					total+=start[i];
			}
			else
			{
				countsolo+=solo[i];
				if(start[i]==ending[i]&&start[i]>0){
					total+=start[i];
					goto jump;
				}
				else if(start[i]==ending[i]&&start[i]==0)
				{
					if(n==1)
						count=2;
					else
						count=3;
				}		
				else if(start[i]>ending[i]+1||start[i]+1<ending[i])
					count=3;
				else{
					total+=min(start[i],ending[i]);
					count++;	
				}
			}
	jump:
/*			if(solo[i]&&start[i]==ending[i]&&start[i]>0)
				continue;
			else if(!solo[i]&&start[i]==ending[i])
				continue;
			else if(solo[i]&&start[i]==ending[i]+1)
				count++;
			else if(solo[i]&&start[i]+1==ending[i])
				count++;
			if(start[i]>=ending[i]+2||start[i]+2<=ending[i])
				count=3;
				count++;
*/			if(count==3)
				break;
		}
//		cout<<count<<" ";
		int temp=0;
			for(i=0;i<26;i++)
				temp+=start[i];
			if(temp<n-1)
				count=3;
			else
				count=2;
		if(count==3)
			printf("The door cannot be opened.");
		else if(total<n-1-countsolo)
			printf("The door cannot be opened.");
		else
			printf("Ordering is possible.");
		printf("\n");
	}
	return 0;
}