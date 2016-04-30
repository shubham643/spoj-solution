import sys
def main():
	t=raw_input()
	m=int(t)
	while m!=0:
		a=raw_input()
		b=a.split(' ')
		p=int(b[0])
		q=int(b[1])
		m-=1
		print p*q
if __name__=='__main__':
	main()