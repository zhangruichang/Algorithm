__author__ = 'Richard'
T=input()
t='hackerrank'
ans=0

for i in range(T):
    s=raw_input()
    s=s.lower()
    si=ti=k=0
    while si+k<len(s) and ti<len(t):
        #s[si+k]=s[si+k].lower()
        if s[si+k]==t[ti]:
            k=k+1
            ti=ti+1
        else:
            k=ti=0
            si=si+1
        if ti==len(t):
            si=si+k; k=ti=0
            ans=ans+1
print ans
