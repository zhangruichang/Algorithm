__author__ = 'richard'

str=raw_input()
[index, ch]=raw_input().split(" ")
index=int(index)
l=list(str)
l[index]=ch
print ''.join(l)