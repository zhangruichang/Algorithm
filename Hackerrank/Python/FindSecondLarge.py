__author__ = 'richard'
n = input()
L = raw_input().strip().split(' ')
L = map(eval, L)
L.sort()
for i in range(len(L)-1, 0, -1):
    if L[i-1] != L[i]:
        print L[i-1]
        break
