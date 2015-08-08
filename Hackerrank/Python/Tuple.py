# Enter your code here. Read input from STDIN. Print output to STDOUT
n=input()
L=[]
L=raw_input().split(' ');
L=map(eval, L)
T=tuple(L)
print hash(T)
