__author__ = 'richard'
# Enter your code here. Read input from STDIN. Print output to STDOUT
m=input()
Lm=raw_input().split(' ')
Lm=map(eval, Lm)
Sm=set(Lm)
n=input()
Ln=raw_input().split(' ')
Ln=map(eval, Ln)
Sn=set(Ln)
Sd=Sm.symmetric_difference(Sn)
Ld=list(Sd)
Ld.sort()
for i in Ld:
    print i
