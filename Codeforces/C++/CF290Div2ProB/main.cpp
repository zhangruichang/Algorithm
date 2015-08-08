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
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e2 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
const int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};
int n, m;
string A[maxn];
bool v[maxn][maxn];
bool Ad(int si, int sj, int curi, int curj)
{
    return ((si==sj) && abs(curi-curj)==1) || ((curi==curj) && abs(si-sj)==1);
}
bool dfs(int si, int sj, int curi, int curj, int len)
{
    if(v[curi][curj]) return 0;

    if(Ad(si, sj, curi, curj) && len>=3) return 1;
    v[curi][curj]=1;
    for(int k=0;k<4;k++)
    {
        int nx=curi+dx[k], ny=curj+dy[k];
        if(!(nx>=n || nx<0 || ny>=m || ny<0) && A[curi][curj]==A[nx][ny] && dfs(si, sj, nx, ny, len+1)) return 1;
    }
    v[curi][curj]=0;
    return 0;
}
int main()
{
    while(cin>>n>>m)
    {

        for(int i=0; i<n; i++) cin>>A[i];
        memset(v, 0, sizeof v); bool OK=0;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++)
        {
            if(dfs(i, j, i, j, 0))
            {
                puts("Yes");
                OK=1;
                goto L1;
            }
        }
 L1:    if(!OK)
            puts("No");
    }
	return 0;
}
