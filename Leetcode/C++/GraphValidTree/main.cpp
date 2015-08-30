/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)
int getint(){
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-'){
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n){
    return !m ? n : GCD(n%m, m);
}
int a[maxn], n, t, m;

class Solution {
public:
  bool v[10000];
  unordered_set<int> edge[10000];
  int n_;
  bool validTree(int n, vector<pair<int, int>>& edges) {
    if(!n) return 1;n_=n;
    for(int i=0;i<n;i++) edge[i].clear();
    for(auto e: edges){
      edge[e.fi].insert(e.se);
      edge[e.se].insert(e.fi);
    }
    memset(v, 0 , sizeof v);
    bool ans = dfs(0);
    for(int i=0;i<n_;i++){
      if(!v[i]) return 0;
    }
    return ans;
  }
  bool dfs(int i){
    if(v[i]) return 0;
    v[i]=1;
    for(auto it=edge[i].begin() ; it!= edge[i].end(); ){
      auto e=*it;
      edge[e].erase(i);
      auto fit=edge[i].find(e);
      it= edge[i].erase(fit);
      if(!dfs(e)) return 0;
    }
    return 1;
  }
} S;

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
  int n=5;
  vector<pii> edges={ {0,1},{0,2},{2,3},{2,4}};
  cout<<S.validTree(n, edges)<<endl;
	return 0;
}
