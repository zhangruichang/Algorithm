__author__ = 'richard'

k=input()
str=raw_input()
s=set()
for i in xrange(len(str)):
    if str[i] not in s:
        s.add(str[i])
        pos.add(i)
