#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 2e3 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
double dp[maxn][maxn];

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n;double p;int t;
    while(cin>>n>>p>>t)
    {
        memset(dp, 0, sizeof dp);
        dp[0][0]=1.0;
        for(int j=1;j<=t;j++) dp[0][j]=(1.0-p)*dp[0][j-1];
        //for(int i=1;i<=n;i++) dp[i][i]=p*dp[i-1][i-1];
        for(int i=1;i<=n;i++) for(int j=i;j<=t;j++)
        {
            if(i<n)//people not full in elevator
                dp[i][j]=p*dp[i-1][j-1]+(1-p)*dp[i][j-1];
            else//full
                dp[i][j]=p*dp[i-1][j-1]+dp[i][j-1];
        }
        double sum=0;
        for(int i=0;i<=n;i++) sum+=double(i)*dp[i][t];
        printf("%.7f\n", sum);
    }
	return 0;
}
