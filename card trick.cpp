#include<iostream>
#include<stdio.h>
#include<list>
using namespace std;

struct node
{
	int index;
	node *next;
};

void cons(node **l,int n)
{
	node *start=new node;
	start->index=0;
	node *temp=start;
	int i;
	for(i=1;i<n;i++)
	{
		node *x=new node;
		x->index=i;
		temp->next=x;
		temp=x;
	}
	temp->next=start;
	*l=start;
	temp=*l;
}

void operate(int *a,node *l,int n)
{
	a[l->next->index]=1;
	l->next=l->next->next;
	int i=2,j;
	while(i!=n+1)
	{
		for(j=0;j<i;j++)
			l=l->next;
		a[l->next->index]=i;
		i++;
		l->next=l->next->next;
	}
}

int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		int a[n];
		node *l;
		cons(&l,n);
		operate(a,l,n);
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}