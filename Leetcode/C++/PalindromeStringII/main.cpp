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
  int n, m;
  string cur, curs;
  char oddch;
  vector<string> ans;
  vector<string> generatePalindromes(string s) {
    n=s.size();
    if(!n) return {};
    unordered_map<char, int> um;
    for(auto e: s){
        um[e]++;
    }
    int oddcnt=0;

    oddch=0;
    for(auto& e: um){
        if(e.second & 1) oddcnt++, e.second--, oddch=e.first;
        if(oddcnt>=2) return {};
    }
    cur.clear();
    for(auto& e: um) cur.insert(cur.end(), e.se/2, e.fi);
    m=cur.size();
    memset(v, 0 , sizeof v);
    curs.clear();ans.clear();
    dfs(0);
    return ans;
  }
  void dfs(int now){
    if(now>=n/2){
      string rev=curs;
      reverse(rev.begin(), rev.end());
      if(n & 1)
        ans.push_back(rev + oddch + curs);
      else
        ans.push_back(rev + curs);
      return ;
    }
    char last=0;
    for(int i=0;i<m;i++){
      if(v[i] || cur[i] == last) continue;
      v[i]=1;
      curs.push_back(cur[i]);
      dfs(now+1);
      v[i]=0;
      curs.pop_back();
      last=cur[i];
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
  string s="";
  auto ans = S.generatePalindromes(s);
  for(auto e: ans){
    cout<<e<<endl;
  }
	return 0;
}
