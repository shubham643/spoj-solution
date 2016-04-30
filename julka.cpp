#include<bits/stdc++.h>
#define ll long long
using namespace std;

void divideit(char *c,int lenc)
{
	//cout<<c;
	int carry=0,i=lenc-1;
	while(i>=0)
	{
	//	cout<<"here";
		int temp=c[i]-'0'+carry*10;
		if(temp%2==1)
			carry=1;
		else
			carry=0;
		c[i]=temp/2+'0';
		i--;
	}
}

void add(char *c,char *b)
{
	char res[500];
	int index=-1;
	int lenc=strlen(c),lenb=strlen(b);
	int i=0,j=lenb-1;
	int carry=0;
	while(i<lenc&&j>=0)
	{
		int temp=c[i]+b[j]-'0'+carry;
		if(temp>'9'){
			temp-='9'+1;
			carry=1;
		}
		else
			carry=0;
		res[++index]=temp;
		i++;
		j--;
	}
	while(i<lenc)
	{
		int temp=c[i]+carry;
		if(temp>'9'){
			temp-='9'+1;
			carry=1;
		}
		else
			carry=0;
		res[++index]=temp;
		i++;
	}
	while(j>=0)
	{
		int temp=b[j]+carry;
		if(temp>'9'){
			temp-='9'+1;
			carry=1;
		}
		else
			carry=0;
		res[++index]=temp;
		j--;
	}
	if(carry)
	{
		res[++index]='1';
		res[++index]='\0';
	}
	for(i=index-1;i>=0;i--)
		cout<<c[i];
	cout<<endl;
}

int main()
{
	int i;
	for (i = 0; i < 10; ++i)
	{
		char a[101];
		char b[101],c[101];
		cin>>a;
		cin>>b;
//		cout<<a<<" "<<b;
		
		int lena=strlen(a),lenb=strlen(b);
		int j;
		i=lena-1;
		j=lenb-1;
		int carry=0;
		while(j>=0)
		{
			int temp=a[i]-b[j]-carry;
//			cout<<"tmp"<<temp;
			if(temp<0){
//				cout<<"still inside"<<temp<<" ";
				carry=1;
				temp+=10;
			}
			else
				carry=0;
	//		cout<<"lenb-1-j"<<lenb-1-j<<" ";
			c[lenb-1-j]=temp+'0';
	//		cout<<"c[lenb-1-i]"<<c[lenb-1-i];
			j--;
			i--;
		}
	//	cout<<"c[0]"<<c[0];
		j=lenb;
		while(i>0)
		{
			int temp=a[i]-carry;
			if(temp<'0')
			{
				temp+=10;
				carry=1;
			}
			else
				carry=0;
			c[j]=temp;
			j++;
			i--;
		}
//		cout<<"ai"<<a[i]<<"carry"<<carry;
		if(a[i]>'1'||(a[i]=='1'&&carry==0)){
//			cout<<"inside";
			c[j]=a[i]-carry;
			j++;
		}
	//	cout<<c[0]<<c[1];
	//	cout<<"j"<<j;
		c[j]='\0';
		int lenc=j;
	//	cout<<"c"<<c<<"   ";
		divideit(c,lenc);
		i=lenc-1;
		while(c[i]=='0')
			i--;
		while(i>=0)
			printf("%c",c[i--]);
        printf("\n");
        add(c,b);
	}
	return 0;
}
