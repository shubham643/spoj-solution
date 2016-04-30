import sys
def main():
	t=input()
	while t>0:
		s=raw_input()
		str=s.split(' ')
		a=0
		temp=0
		prev=0
		for i in str:
			now=len(i)
			if now==prev:
				temp+=1
				if temp>a:
					a=temp
			else:
				temp=1
				prev=len(i)
		print a
		t-=1

if __name__ == '__main__':
	main()