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
const int maxn = 1e2 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
bool v[maxn];
bool validcolor[maxn];
int n;
vector<int> mat[maxn][maxn];
int dfs(int cur, int e, int color)
{
    if(cur==e) return 1;
    if(v[cur]) return 0;
    v[cur]=1;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(i==cur) continue;
        for(auto ele: mat[cur][i])
            if(ele==color && dfs(i, e, color)) {v[cur]=0; return 1;}
    }
    v[cur]=0;
    return 0;
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int  m, q, qu, qv, x,y, c;
    for(int i=0;i<maxn;i++) for(int j=0;j<maxn;j++) mat[i][j].clear();
    cin>>n>>m;
    for(int i=0;i<m;i++) cin>>x>>y>>c, mat[x][y].push_back(c), mat[y][x].push_back(c);
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>qu>>qv;
        memset(validcolor, 0, sizeof validcolor);
        for(int i=1;i<=n;i++)
        {
            memset(v, 0 ,sizeof v);
            if(i==qu) continue;
            v[qu]=1;
            for(auto ele: mat[qu][i])
                if(!validcolor[ele] && dfs(i, qv, ele)) validcolor[ele]=1;;
        }
        int sum=0;for(int j=1;j<=m;j++) sum+=validcolor[j];
        cout<<sum<<endl;
    }
	return 0;
}
