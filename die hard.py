import sys

save=[[0 for x in range(10001)] for x in range(10001)]

def findit(a,b,last):
	if a<=0:
		return -1
	if b<=0:
		return -1
	if save[a][b]!=0:
		return save[a][b]
	p=q=r=-1
	x=1
	if x!=last:
		p=findit(a+3,b+2,x)+1
	x=2
	if x!=last:
		q=findit(a-5,b-10,x)+1
	x=3
	if x!=last:
		r=findit(a-20,b+5,x)+1
	save[a][b]=max(p,max(q,r))
	return save[a][b]	



def main():
	t=input()
	t=int(t)
	while t>0:
		a=input()
		b=input()
		res=findit(a,b,0)
		t-=1
		print res
if __name__=='__main__':
	main()
