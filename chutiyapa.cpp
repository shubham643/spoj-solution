#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i;
	for(i=0;i<1000;i++)
	{
		if(i%2)
			printf("%c",i%26 + 'a');
		else
			printf("%c",i%26 + 'A');
	}
	return 0;
}