import sys
def main():
	while(1):
		a=raw_input()
		b=a.split(' ')
		p=int(b[0])
		q=int(b[1])
		if p==0 and q==0:
			return
		print pow(p,q)
if __name__=='__main__':
	main()