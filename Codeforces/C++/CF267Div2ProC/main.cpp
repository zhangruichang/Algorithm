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
const int maxn = 5e3+ + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
#define f first
#define s second
int getint(){
	int t = 0, flag = 1;
	char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
	{
		t = t * 10 + c - '0';
		c = getchar();
	}
	return t*flag;
}
int maxsum, n, m, k;
/*
void dfs(int i, int ki, int sum)
{
    if(ki==k)
    {
        maxsum=max(maxsum, sum);
        return ;
    }
    if(i>n-m || (k-ki)*m>(n-i))
    {
        return ;
    }
    for(int j=i;j<=n-m;j++)
    {
        dfs(j+m,ki+1, sum+prefix[j]);
    }
}*/
LL dp[maxn][maxn];
LL prefix[maxn];
LL a[maxn];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>n>>m>>k)
    { //a[i-m]+...a[i-1]=prefix[i]-prefix[i-m];
        prefix[0]=0;
        for(int i=0;i<n;i++) cin>>a[i], prefix[i+1]=prefix[i]+a[i];
        for(int i=m;i<=n;i++) for(int j=1;j<=k;j++)
            dp[i][j]=max(dp[i-m][j-1]+prefix[i]-prefix[i-m], dp[i-1][j]);
        cout<<dp[n][k]<<endl;
    }
	return 0;
}
