#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s[1001];
	while(scanf("%s",s)!=EOF)
	{
		char a[1001];
		scanf("%s",a);
		int f1[26],f2[26];
		int i;
		for(i=0;i<26;i++)
			f1[i]=f2[i]=0;
		int len1=strlen(s);
		int len2=strlen(a);
		for(i=0;i<len1;i++)
			f1[s[i]-'a']++;
		for(i=0;i<len2;i++)
			f2[a[i]-'a']++;
		for(i=0;i<26;i++)
		{
			int j;
			for(j=0;j<min(f1[i],f2[i]);j++)
				printf("%c",i+'a');
		}
		printf("\n");
	}
	return 0;
}