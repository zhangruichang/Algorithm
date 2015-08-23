#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#define LL long long
#define MAXN 100050
using namespace std;
vector<int>e[MAXN];
LL d[MAXN];
int a[MAXN];
bool v[MAXN];
/*
void dfs(int cur,int fa)
{
	d[cur]=a[cur];
    for(auto u: e[cur])
    {
		if(u==fa)continue;
		dfs(u,cur);
		d[cur]+=d[u];
	}
}*/
int dfs(int cur)
{
    if(v[cur]) return d[cur];
    int sum=a[cur];
    v[cur]=1;
    for(auto u: e[cur])
    {
        if(v[u]) continue;
        sum+=dfs(u);
    }
    return d[cur]=sum;
}
int main()
{
	int tt,ri=0;
	scanf("%d",&tt);
	while(tt--)
	{
		int n,s;
		scanf("%d%d",&n,&s);
		for(int i=0;i<=n;++i) e[i].clear();
		for(int i=1;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		memset(v, 0 ,sizeof v);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		dfs(s);
		cout<<d[s]<<endl;
		LL mx=0;
        for(auto u: e[s])
			mx=max(mx, d[u]);
		printf("Case #%d: %lld\n",++ri,mx);
	}
	return 0;
}
