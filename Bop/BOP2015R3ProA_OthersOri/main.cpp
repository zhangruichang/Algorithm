#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#define LL long long
#define MAXN 100050
using namespace std;
vector<int>e[MAXN];
LL d[MAXN];
int a[MAXN];
void dfs(int cur,int fa){
	d[cur]=a[cur];
	for(int i=0;i<e[cur].size();++i){
		int u=e[cur][i];
		if(u==fa)continue;
		dfs(u,cur);
		d[cur]+=d[u];
	}
}
int main()
{
	int tt,ri=0;
	scanf("%d",&tt);
	while(tt--)
	{
		int n,s;
		scanf("%d%d",&n,&s);
		for(int i=0;i<=n;++i)
			e[i].clear();
		for(int i=1;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		dfs(s,-1);
		LL mx=0;
		for(int i=0;i<e[s].size();++i){
			int u=e[s][i];
			if(d[u]>mx)
				mx=d[u];
		}
		printf("Case #%d: %lld\n",++ri,mx);
	}
}
