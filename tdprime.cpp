#include<bits/stdc++.h>
using namespace std;
#define pc(x) putchar_unlocked(x);

bool flag[10000000];
int saved[10000];
int indexed;
int counting;

    inline void writeInt (int n)
    {
        int N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
        pc('\n');
    }

void compute()
{
	int i,j;
	int b=10000;
	for(i=2;i<=b;i++)
	{
		if(!flag[i])
		{
			if(counting%100==1)
				writeInt(i);
			counting++;
			saved[++indexed]=i;
			for(j=i*i;j<10000000;j+=i)
				flag[j]=true;
		}
	}
	for(i;i<10000000;i++)
	{
		if(!flag[i]){
			if(counting%100==1)
				writeInt(i);
			counting++;
		}
	}
}

void findit(int a,int b)
{
	int i,j;
	for(i=0;i<=indexed;i++)
	{
		j=saved[i]-a%saved[i];
		if(j==saved[i])
			flag[0]=true;
		for(j;j<10000000;j+=saved[i])
			flag[j]=true;
	}
	for(i=0;i<b-a;i++)
	{
		if(!flag[i]){
			if(counting%100==1)
				writeInt(a+i);
			counting++;
		}
	}
}

int main()
{
	counting=1;
	indexed=-1;
	compute();
	int i;
	for(i=1;i<=9;i++)
	{
		int j;
		for(j=0;j<10000000;j++)
			flag[j]=false;
		findit(i*10000000,(i+1)*10000000);
	}
	return 0;
}