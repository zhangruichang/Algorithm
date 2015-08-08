__author__ = 'richard'
n=input()
L=raw_input().strip().split(' ')
L=map(eval, L)
L.sort()
L[len(L)-1]= (2 if L[len(L)-1]==1 else 1)
L.sort()
print str(L).replace(r'[\[\]]','')
print [str(i) for i in L]
print ' '.join([str(i) for i in L])
#strL=str(L)
#for i in range(L):
#    print i,
