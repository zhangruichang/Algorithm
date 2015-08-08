__author__ = 'Richard'
import re;
t=input()
for i in range(t):
    s=raw_input()
    if(re.match('[A-Z]{5}[0-9]{4}[A-Z]{1}', s)):
        print 'YES'
    else:
        print 'NO'