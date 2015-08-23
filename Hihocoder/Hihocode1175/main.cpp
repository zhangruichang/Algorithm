/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
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
#include<sstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)
int getint(){
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int a[maxn], n, t, m, k;
vector<int> e[maxn];
int deg[maxn];
int MOD=142857;
void dfs(int now){
    deg[now]=-1;
    for(auto i: e[now]){
        deg[i]--;
        a[i]=(a[i]+a[now])%MOD;
        if(!deg[i]) dfs(i);
    }
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int x, u, v;
    cin>>n>>m>>k;
    fill_n(a, maxn, 0);
    for(int i=0;i<maxn;i++) e[i].clear(), deg[i]=0;
    for(int i=0;i<k;i++) cin>>x, a[x]++;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        e[u].push_back(v);deg[v]++;
    }
    for(int i=1;i<=n;i++){
        if(!deg[i]) dfs(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+a[i])%MOD;
    }
    cout<<ans<<endl;
	return 0;
}
