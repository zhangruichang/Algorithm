//By Lin
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<cctype>
#include<cmath>

#define eps 1e-9
#define sqr(x) ((x)*(x))
#define Rep(i,n) for(int i = 0; i<n; i++)
#define foreach(i,n) for( __typeof(n.begin()) i = n.begin(); i!=n.end(); i++)
#define X first
#define Y second
#define mp(x,y) make_pair(x,y)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define N 100010

int ecnt;
struct Edge {
	int to;
	Edge *next;
}*mat[N], edges[N*2];
void link(int x, int to) {
	edges[ecnt].to = to;
	edges[ecnt].next = mat[x];
	mat[x] = &edges[ecnt++];
}

LL ans;
int val[N];

LL dfs(int x, int father = -1) {
	LL size = 0;
	for (Edge *p = mat[x]; p; p = p->next) {
		int to = p->to;
		if (to == father) continue;
		LL t = dfs(to, x);
		ans = max(ans, t);
		size += t;
	}
	size += val[x];
	return size;
}
int		main(){
	int cas, tt = 0;
	scanf("%d", &cas);
	while (cas --) {
		int n, source;
		scanf("%d%d", &n, &source);
		source --;
		ecnt = 0;
		memset(mat, 0, sizeof mat);
		Rep(i, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			x--, y--;
			link(x, y);
			link(y, x);
		}
		Rep(i, n) scanf("%d", &val[i]);
		ans = 0;
		dfs(source);
		printf("Case #%d: ", ++tt);
		cout << ans << endl;
	}
	return 0;
}
