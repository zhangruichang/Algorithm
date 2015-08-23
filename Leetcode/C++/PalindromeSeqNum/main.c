#include <stdio.h>
#include <stdlib.h>

const int maxn=1e+2;
int dp[maxn][maxn];
int PalindromeSeqNum(char* s)
{
    int len=strlen(s);
    memset(dp, 0 ,sizeof(dp));
    for(int i=0;i<len;i++) dp[i][i]=1;
    for(int l=2;l<=len;l++)
    {
        for(int i=0;i<len;i++)
        {
            int j=i+l-1;
            if(j>=len) continue;
            if(s[i]!=s[j]) dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            else dp[i][j]=dp[i+1][j]+dp[i][j-1]+1;
        }
    }
    return dp[0][n-1];
}

int main()
{
    char s[maxn];
    while(~scanf("%s", s))
        cout<<PalindromeSeqNum(s)<<endl;
    //printf("Hello world!\n");
    return 0;
}
