/* ***********************************************
Author        :kuangbin
Created Time  :2015/5/9 13:56:55
File Name     :F:\ACM\2015ACM\比赛练习\编程之美2015复赛\A.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 100010;
struct Edge{
	int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
void init(){
	tot = 0;
	memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
int x[MAXN];
long long dp[MAXN];
int que[MAXN];
int fa[MAXN];
void dfs(int n,int s){
	int st,ed;
	st = ed = 0;
	que[ed++] = s;
	fa[s] = s;
	for(;st < ed;st++){
		int u = que[st];
		for(int i = head[u];i != -1;i = edge[i].next){
			int v = edge[i].to;
			if(v == fa[u])continue;
			fa[v] = u;
			que[ed++] = v;
		}
	}
	for(int i = n-1;i >= 0;i--){
		int u = que[i];
		long long tmp = 0;
		for(int i = head[u];i != -1;i = edge[i].next){
			int v = edge[i].to;
			if(v == fa[u])continue;
			tmp += dp[v];
		}
		dp[u] = tmp + x[u];
	}
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
	int iCase = 0;
	int n,s;
	scanf("%d",&T);
	while(T--){
		iCase++;
		scanf("%d%d",&n,&s);
		int u,v;
		init();
		for(int i = 1;i < n;i++){
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		for(int i = 1;i <= n;i++)scanf("%d",&x[i]);
		dfs(n,s);
		long long ans = 0;
		for(int i = head[s];i != -1;i = edge[i].next){
			v = edge[i].to;
			ans = max(ans,dp[v]);
		}
		printf("Case #%d: %lld\n",iCase,ans);
	}
    return 0;
}
