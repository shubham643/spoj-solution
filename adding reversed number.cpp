#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a[100000],b[100000],res[100000];
        int i,j;
        scanf("%s%s",a,b);
        int lena=strlen(a),lenb=strlen(b);
        while(a[lena-1]=='0'&&lena-1>=0)
            lena--;
        while(b[lenb-1]=='0'&&lenb-1>=0)
            lenb--;
    //    cout<<lena<<" "<<lenb<<endl;
        i=j=0;
        while(i<lena&&a[i]=='0')
            i++;
        while(j<lenb&&b[j]=='0')
            j++;
        if(i==lena)
        {
            if(i>0)
               i--;
            else if(lena==0)
                lena++;
        }
        if(j==lenb)
        {
            if(j>0)
               j--;
            else if(lenb==0)
                lenb++;
        }
        int index=-1;
        int carry=0;
        while(i<lena&&j<lenb)
        {
            res[++index]=a[i]+b[j]-'0'+carry;
            if(res[index]>'9')
            {
                carry=1;
                res[index]=res[index]-'9'-1+'0';
      //          if(index==0)
        //            cout<<a[index]<<" "<<b[index]<<" "<<res[index]<<endl;
            }
            else
                carry=0;
            i++; j++;
        }
        while(i<lena)
        {
            res[++index]=a[i]+carry;
            if(res[index]>'9')
            {
                carry=1;
                res[index]=res[index]-'9'-1;
            }
            else
                carry=0;   
            i++;
        }
        while(j<lenb)
        {
            res[++index]=b[j]+carry;
            if(res[index]>'9')
            {
                carry=1;
                res[index]=res[index]-'9'-1;
            }
            else
                carry=0;
            j++;   
        }
        if(carry)
            res[++index]='1';
        res[++index]='\0';
        i=0;
        while(i<index&&res[i]=='0')
            i++;
        if(i==index)
            printf("0\n");
        else
        {
            while(i<index){
                printf("%c",res[i]);
                i++;
            }
            printf("\n");
        }
    }
}