#include<bits/stdc++.h>
using namespace std;

int general[100009];
int city[100009];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,g;
		scanf("%d%d",&n,&g);
		int i,val;
		for(i=1;i<=g;i++)
		{
			scanf("%d",&general[i]);
		}
		int q;
		scanf("%d",&q);
		for(i=0;i<q;i++)
		{
			int type;
			scanf("%d",&type);
			if(type==1)
			{
				char cat;
				int id1,id2;
				scanf("%c%d%d",&cat,&id1,&id2);
				if(cat=='g')
				{
					city[id2]=id1;
				}
				else
					city[id2]=city[id1];
			}
			else if(type==2)
			{
				int id;
				scanf("%d",&id);
				if(general[city[id]]==1)
					printf("Dukkar\n");
				else
					printf("Mathur\n");
			}
			else
			{
				int id;
				scanf("%d",&id);
				if(general[id]==1)
				{
					general[id]=0;
				}
				else if(general[id]==0)
				{
					general[id]=1;
				}
			}
		}
	}
	return 0;
}