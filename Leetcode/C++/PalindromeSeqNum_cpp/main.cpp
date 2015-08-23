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
const int maxn = 1e3 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define inf 0x3f3f3f3f
int dp[maxn][maxn];
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
int bitcount(int x) {//O(cnt), cnt is 1 number of x
    int res = 0;
    while (x) {
	res++;
	x -= x & -x;
    }
    return res;
}

//const int maxn=1e+5;

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
    return dp[0][len-1];
}

bool Check(int a[], int n, int k)//1,2,3,4, k=0 return 1;
{
    int cnt=0;
    for(int i=0;i<n;i++)
        if(a[i]!=i+1) cnt++;
    return k>=cnt && (k-cnt)%2==0;
}

int dij(int s, int e)//directed graph s->e mindist, if not reachable, return INT_MIN;
{
    memset(v, 0, sizeof(v));
    for(int i=0;i<n;i++)
        dist[i]=a[s][i];
    v[s]=1;
    for(int i=0;i<n-1;i++)//add n-1 pts
    {
        int mindis=inf, mindisi=-1;
        for(int j=0;j<n;j++)
        {
            if(v[j]) continue;
            if(mindis>dist[j]) mindis=dist[j], mindisi=j;
        }
        if(mindisi==-1) break;//all remaining points unreachable
        v[mindisi]=1;
        for(int j=0;j<n;j++)
        {
            if(v[j]) continue;
            //if(dist[j]>dist[mindisi]+a[mindisi][j])
            dist[j]=min(dist[j], dist[mindisi]+a[mindisi][j]);
        }
    }
    return dist[e];
}
int main()
{
    char s[maxn];
    while(~scanf("%s", s))
        cout<<PalindromeSeqNum(s)<<endl;
    //printf("Hello world!\n");
    return 0;
}
