__author__ = 'richard'
def F(s):
    t='CODEFORCES'
    i=0
    j=0
    tc=0
    f=0
    while i<len(s) and j<len(t):
        if s[i]==t[j]:
            j+=1
            f=1
        elif f==0 or (f==1 and tc==0):
            tc+=1
            f=0
        else:
            return False
        i+=1
    return j==len(t)

s=raw_input()
print 'YES' if F(s) else 'NO'