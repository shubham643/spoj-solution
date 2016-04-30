import sys
def main():
	n=input()
	n=int(n)
	last=1;
	lastlast=1
	for i in range(2,n+1):
		temp=lastlast+last
		last=lastlast
		lastlast=temp
	print lastlast+last
if __name__=='__main__':
	main()