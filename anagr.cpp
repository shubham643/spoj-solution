#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	cin.ignore();
	while(t--)
	{
		string a,b;
		getline(cin,a);
		getline(cin,b);
		istringstream issa(a,istringstream::in);
		istringstream issb(b,istringstream::in);
		int flaga[26];
		int i,j;
		for(i=0;i<26;i++)
			flaga[i]=0;
		string word;
		while(issa>>word)
		{
			int len=word.length();
			for(i=0;i<len;i++)
			{
				if(word[i]<'A'||word[i]>'z'||(word[i]<'a'&&word[i]>'Z'))
					continue;
				if(word[i]>='a')
					flaga[word[i]-'a']++;
				else
					flaga[word[i]-'A']++;
			}
		}
		while(issb>>word)
		{
			int len=word.length();
			for(i=0;i<len;i++)
			{
				if(word[i]<'A'||word[i]>'z'||(word[i]<'a'&&word[i]>'Z'))
					continue;
				if(word[i]>='a')
					flaga[word[i]-'a']--;
				else
					flaga[word[i]-'A']--;
			}
		}
		for(i=0;i<26;i++)
			if(flaga[i]!=0)
				break;
		if(i==26)
			printf("YES\n");
		else
		{
			int val=0;
			for(i=0;i<26;i++)
			{
				if(flaga[i]<0&&val==0)
					val=1;
				else if(flaga[i]<0&&val==2||flaga[i]>0&&val==1)
				{
					break;
				}
				else if(flaga[i]>0&&val==0)
					val=2;
				else if(flaga[i]<0)
					flaga[i]=-flaga[i];
			}
			if(i!=26)
				printf("NO LUCK\n");
			else
			{
				int count=0;
				for(i=0;i<26;i++)
				{
					if(flaga[i]&1)
						count++;
				}
				if(count>1)
					printf("NO LUCK\n");
				else
				{
					list<char> ff;
					list<char> ss;
					char mid=' ';
					for(i=0;i<26;i++)
					{
						if(flaga[i]&1){
							mid=i+'a';
							flaga[i]--;
							for(j=0;j<flaga[i]/2;j++)
							{
								ff.push_back(i+'a');
								ss.push_back(i+'a');
							}
						}
						else
						{
							for(j=0;j<flaga[i]/2;j++)
							{
								ff.push_back(i+'a');
								ss.push_back(i+'a');
							}	
						}
					}
					while(!ff.empty())
					{
						printf("%c",ff.front());
						ff.pop_front();
					}
					if(mid!=' ')
						printf("%c",mid);
					while(!ss.empty())
					{
						printf("%c",ss.back());
						ss.pop_back();
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
}