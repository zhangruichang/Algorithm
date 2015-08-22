__author__ = 'zhangruichang'
import sys


def get_similarity(a, b):
    m, n = len(a), len(b)
    dp = [[0 for col in range(n+1)] for row in range(m+1)]
    # m*n dp[][]=0
    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (1 if a[i - 1] != b[j - 1] else 0))
    return dp[m][n]


# dp[i][j] : pre line i and pre line j code diff
#sim[i][j]: line i-1th and line j-1th diff if i>=1 and j>=1
#           line i-1th and empty line if j==1
#           line j-1th and empty line if j==1



if __name__ == "__main__":
    file_name1 = sys.argv[1]
    file_name2 = sys.argv[2]
    code_file1 = open(file_name1, "r")
    code_file2 = open(file_name2, "r")

    m = 0
    code_line1=[]
    for i in code_file1:
        code_line1.append(i)
        m+=1
    n = 0
    code_line2=[]
    for i in code_file2:
        code_line2.append(i)
        n+=1

    similarity = []
    simi_line = [0]
    for j in code_line2:
        simi_line.append(len(j))
    similarity.append(simi_line)
    for i in code_line1:
        simi_line = [len(i)]
        for j in code_line2:
            simi_line.append(get_similarity(i, j))
        similarity.append(simi_line)

    #similarity is m+1 * n+1 matrix, exactly distance, not similarity
    print 'code file 1 has '+str(m)+' lines', ' code file 2 has '+str(n)+' lines'
    dp = [[0 for col in range(n+1)] for row in range(m+1)]
    for i in range(1, m + 1):
        dp[i][0] = dp[i-1][0] + similarity[i][0]
    for j in range(1, n + 1):
        dp[0][j] = dp[0][j-1] + similarity[0][j]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            dp[i][j] = min(dp[i - 1][j] + similarity[i][0], dp[i][j - 1] + similarity[0][j],
                           dp[i - 1][j - 1] + similarity[i][j])
    #print dp
    print 'distance between code file 1 and code file 2 is '+str(dp[m][n])

    i, j = m, n
    log = []
    while i > 0 or j > 0:
        if i>=1 and dp[i][j] == (dp[i - 1][j] + similarity[i][0]):
            log.append('delete code file 1 line '+str(i)+': '+code_line1[i-1])
            i-=1
            #log.append('delete line i')
        elif j>=1 and dp[i][j] == (dp[i][j - 1] + similarity[0][j]):
            log.append('insert code file 2 line '+str(j)+': '+code_line2[j-1])
            j-=1
            #log.append('delete line j')
        elif i>=1 and j>=1 and dp[i][j] == (dp[i - 1][j - 1] + similarity[i][j]):
            if similarity[i][j]!=0:
                log.append('replace code file 1 line '+str(i)+' : '+code_line1[i-1]+' to code file 2 line '+str(j)+' : '+code_line2[j-1])
                '''
                s , t = len(code_line1[i-1]), len(code_line2[j-1])
                while s > 0 or t > 0:
                    if s>=1 and similarity[i][j] == similarity[i-1][j] + code_line1[i][s-1]:
                        print 'delete '
                '''
            i-=1
            j-=1
            #log.append('replace line i as line j')
            #call get line i as line j detail
    log.reverse()
    for line in log:
        print line