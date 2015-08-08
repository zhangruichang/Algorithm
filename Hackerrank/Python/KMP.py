__author__ = 'richard'


def GetNext(pat, Next):
    n=len(pat)
    Next[0]=-1
    for i in range(n-1):
        k=Next[i]
        while k!=-1 and pat[k]!=pat[i]:
            k=Next[k]
        Next[i+1]=k+1

def KMP(str, pat):
    Next=[0]*len(pat)
    GetNext(pat, Next)
    m, n, i, j=len(str), len(pat), 0, 0
    while i<m and j<n:
        if j==-1 or str[i]==pat[j]:
            i, j=i+1, j+1
        else:
            j=Next[j]
        if j==n:
            return i-j
    return -1

str='zhangruichang'
pat='chang'
print KMP(str,pat)