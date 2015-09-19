#ifndef EXPRESSIONADDOPERATOR_AC_H_INCLUDED
#define EXPRESSIONADDOPERATOR_AC_H_INCLUDED
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
private:
  // cur: {string} expression generated so far.
  // pos: {int}    current visiting position of num.
  // cv:  {long}   cumulative value so far.
  // pv:  {long}   previous operand value.
  // op:  {char}   previous operator used.
  vector<string> res;
  string num;
  int target;
  void dfs(string cur, int pos, long cv, long prev_value, char prev_op) {
    if (pos == num.size() && cv == target) {
      res.push_back(cur);
      return ;
    }
    for (int i=pos+1; i<=num.size(); i++) {
      string t = num.substr(pos, i-pos);
      long long now = stol(t);
      if (i-pos>1 && num[pos]=='0') continue;
      dfs(cur+'+'+t, i, cv+now, now, '+');
      dfs(cur+'-'+t, i, cv-now, now, '-');
      int cur_value;
      if(prev_op=='-') cur_value=cv+prev_value - prev_value*now;
      else cur_value=cv-prev_value + prev_value*now;
      dfs(cur+'*'+t, i, cur_value , prev_value*now, prev_op);
    }
  }

public:
  vector<string> addOperators(string num_, int target_) {
    res.clear();
    num=num_;target=target_;
    if (num.empty()) return res;
    for (int i=1; i<=num.size(); i++) {
      string s = num.substr(0, i);
      long long cur = stol(s);
      if (i>1 && s[0]=='0') continue;
      dfs(s, i, cur, cur, '#');         // no operator defined.
    }
    return res;
  }
};

#endif // EXPRESSIONADDOPERATOR_AC_H_INCLUDED
