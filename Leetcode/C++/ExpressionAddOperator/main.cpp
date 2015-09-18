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
  char opt[3]={'+', '-', '*'};
  int n, target;
  string num, cur;
  vector<string> ans;
  vector<string> addOperators(string num_, int target_) {
    target=target_;
    num=num_;
    cur.clear(), ans.clear();
    n=num.size();
    dfs(0);
    return ans;
  }

  void dfs(int now){
    if(now>=n-1){
        cur+=num[n-1];
        if(f(cur)==target){
          ans.push_back(cur);
        }
        cur.pop_back();
        return ;
    }
    for(int i=0;i<3;i++){
      cur+=num[now];
      cur+=opt[i];
      dfs(now+1);
      cur.pop_back();
      cur.pop_back();
    }
  }

  bool higher(char c1, char c2){
    if(c1=='#'){
      return 0;
    }else if(c1=='*' ){
      return 1;
    }else if(c1=='+' || c1=='-'){
      return c2!='*';
    }else return 0;
  }

  int f(string s){
    s = '#' + s + '#';
    stack<char> optst;
    stack<int> numst;
    for(int i=0;i<s.size();i++){
      auto e=s[i];
      if(e=='+' || e=='-' || e=='*' || e=='#'){
        if( !optst.empty() && higher( optst.top(), e ) ){
          while(!optst.empty() && higher( optst.top(), e )){
            if(numst.empty()) break;
            int num2=numst.top();numst.pop();
            if(numst.empty()) break;
            int num1=numst.top();numst.pop();
            char opte=optst.top();optst.pop();
            numst.push(cal(num1, opte, num2));
          }
          optst.push(e);
        }else if(!optst.empty() && optst.top()=='#' && e== '#'){
          break;
        }else{
          optst.push(e);
        }
      }else{
        numst.push(e-'0');
      }
    }
    return numst.top();
  }

  int cal(int num1, char e, int num2){
    if(e=='+') return num1+num2;
    else if(e=='-') return num1-num2;
    else if(e=='*') return num1*num2;
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
  string num="3456237490";
  int target=9191;
  auto ans = S.addOperators(num, target);
  for(auto e: ans) cout<<e<<endl;
	return 0;
}
