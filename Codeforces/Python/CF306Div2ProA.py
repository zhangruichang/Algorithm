__author__ = 'richard'
import re

s = raw_input()
#**AB**BA**
p1 = re.compile('[A-Z]*AB[A-Z]*BA[A-Z]*')
p2 = re.compile('[A-Z]*BA[A-Z]*AB[A-Z]*')
#***BA**AB**
print 'YES' if p1.match(s) or p2.match(s) else 'NO'