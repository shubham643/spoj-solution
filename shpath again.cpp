#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
 
const int maxn = 10010, inf = 800000;
 
vector <int> D(maxn);
vector < vector < pair<int,int> > > graph(maxn);
map <string,int> getByName;
int n;
 
void update()
{
 
}
 
int dijkstra(int start, int end)
{
	set < pair <int,int> > Q;
	D[start] = 0;
 
	Q.insert( make_pair( D[start], start ) );
 
	while( Q.empty() == false )
	{
		pair <int,int> pr = *Q.begin();
/*		
		if( pr.second == end )
			return pr.first;
*/
		Q.erase( Q.begin() );
 
		for( vector < pair<int,int> >::iterator it = graph[ pr.second ].begin(); it != graph[ pr.second ].end(); it++ )
		{
			int to = it->first, cost = it->second;
 
			if( D[to] > D[ pr.second ] + cost )
			{
				if( D[to] != inf )
					Q.erase( Q.find( make_pair( D[to], to ) ) );
				D[to] = D[ pr.second ] + cost;
				Q.insert( make_pair( D[to], to ) );
			}
		}
	}
	return D[end];
}
 
void SHPATH()
{
	getByName.clear();
	graph.clear();
 
	int i, j, to, w, a, b, c, n1;
	string str, str1;
	char name[25], name1[25];
 
	scanf("%d", &n);

	graph.resize(n+1);
 
	for(i = 0; i < n; ++i)
	{
		scanf("%s", &name); str = name;
		getByName[ str ] = i;
 
		scanf("%d", &n1);
		for(j = 0; j < n1; ++j)
		{
			scanf("%d%d", &to, &w);
			graph[i].push_back( make_pair( to-1, w ) );
		}
	}
 
	scanf("%d", &n1);
	for(i = 0; i < n1; ++i)
	{
		D.clear();
		D.resize(maxn,inf);
 
		scanf("%s" , &name);
		scanf("%s" , &name1);
 
		str = name;
		str1 = name1;
 
		a = getByName[ str ];
		b = getByName[ str1 ];
		c = dijkstra(a, b);
 
		printf("%d\n", c); 
 
	}
}
 
int main()
{
	int testcase;
	scanf("%d", &testcase);
 
	while( testcase-- )
		SHPATH();
 
	return 0;
}