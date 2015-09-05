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

class Solution {
public:
  vector<bool> col, pie, na;
  int n;
  vector<vector<string>> ans;
  vector<string> b;
  vector<vector<string>> solveNQueens(int n_) {
    ans.clear();
    n = n_;
    string line(n, '.');
    b.assign(n, line);
    col.assign(n, 0);
    pie.assign(2*n-1, 0);
    na.assign(2*n-1, 0);
    dfs(0);
    return ans;
  }
  void dfs(int i){
    if(i>=n){
      ans.push_back(b);
      return ;
    }
    for(int j=0;j<n;j++){
      if(col[j] || pie[j-i+n-1] || na[i+j]) continue;
      col[j]=pie[j-i+n-1]=na[i+j]=1;
      b[i][j]='Q';
      dfs(i+1);
      col[j]=pie[j-i+n-1]=na[i+j]=0;
      b[i][j]='.';
    }
  }
};

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/

	return 0;
}
