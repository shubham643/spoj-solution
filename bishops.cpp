/* package whatever; // don't place package name! */
import java.math.*;
import java.util.*;
import java.lang.*;
import java.io.*;

class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext())
		{
			BigInteger ans,p,q;
			BigInteger tt=new BigInteger("2");
			p=new BigInteger("1");
			q=new BigInteger("0");
			BigInteger n=sc.nextBigInteger();
			if(n.compareTo(p)==0)
			{
				System.out.println(n);
				continue;	
			}
			if(n.compareTo(q)==0)
			{
				System.out.println(n);
				continue;		
			}
			ans=n.multiply(tt);
			ans=ans.subtract(tt);
			System.out.println(ans);
		}
	}
}