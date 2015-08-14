__author__ = 'zhangruichang'
import sys

def get_similarity(a, b):
    m, n =len(a), len(b)
    dp=[[0]*n]*m
    #m*n dp[][]=0
    for i in range(m+1):
        dp[i][0]=i
    for j in range(n+1):
        dp[0][j]=j
    for i in range(1, m+1):
        for j in range(1, n+1):
            dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+ (1 if a[i-1]!=b[j-1] else 0))
    return dp[m][n]

if __name__ == "__main__":
    file_name1 = sys.argv[1]
    file_name2 = sys.argv[2]
    code_file1 = open(file_name1, "r")
    code_file2 = open(file_name2, "r")
    similarity=[]
    m, n = 0, 0
    for i in code_file1:
        simi_line=[]
        for j in code_file2:
            simi_line.append( get_similarity(i, j))
            n+=1
        similarity.append(simi_line)
        m+=1
    for i in range(m+1):
        dp[i][0]=similarity[i][0]
    for j in range(n+1):
        dp[0][j]=similarity[0][j]
    for i in range(1, m+1):
        for j in range(1,n+1):
            dp[i][j]=min(dp[i-1][j]+similarity[i][0], dp[i][j-1]+similarity[0][j], dp[i-1][j-1]+similarity[i][j])
    print dp[m][n]
    i, j = m, n
    log=[]
    while m>=0 and n>=0:
        if dp[i][j] == dp[i-1][j]+similarity[i][0]:
            log.append('insert line i')
        elif dp[i][j] == dp[i][j-1]+similarity[0][j]:
            log.append('delete line j')
        else:
            log.append('replace line i as line j')
            #call get line i as line j detail