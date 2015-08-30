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
  vector<vector<int>> ans;
  vector<int> cur;
  int  n ;
  vector<vector<int>> getFactors(int n_) {
    ans.clear();cur.clear();
    if (n_ == 1) return {};
    n = n_;
    dfs(n, 1);
    return ans;
  }
  void dfs(int now, int pro){
    if(now == 1) {
      ans.push_back(cur);
      return ;
    }
    int last= (!cur.empty()) ? cur.back() : 2;
    for(int i=last;i < n;i++){
      if(pro * i > n) return ;
      if(now % i) continue;
      cur.push_back(i);
      dfs(now/i, pro*i);
      cur.pop_back();
    }
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
  auto ans = S.getFactors(2);
  for(auto se: ans){
    for(auto e: se){
      cout<<e<<" ";
    }
    cout<<endl;
  }
	return 0;
}
