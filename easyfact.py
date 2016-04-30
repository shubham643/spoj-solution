import sys
def main():
	t=input()
	while t!=0:
		a=raw_input()
		b=a.split(' ')
		p=float(b[0])
		q=float(b[1])
		count=0
		res=p
		p-=1
		while p!=1:
			res=res*p
			p-=1
		n=2
		while n*n+n<=2*res:
			a=(2*res)-n*n+n
			a=a/(2*n)
			temp=int(a)
			if(a==temp):
				count+=1
				count=(count%q)
			n+=1
		t-=1
	print int(count)
if __name__=='__main__':
	main()