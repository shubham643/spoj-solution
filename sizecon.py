import sys
def main():
	t=raw_input()
	sum=0
	while t:
		val=raw_input()
		if val>0:
			sum+=val
		t-=1
	print sum
if __name__ == '__main__':
	main()