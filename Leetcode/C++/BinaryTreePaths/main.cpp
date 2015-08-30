/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<bits/stdc++.h>
#include"../structlib.h"
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

template <typename T>
string to_string(T value)
{
  //create an output string stream
  ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}

class Solution {
public:
    vector<string> ans;
    string cur;
    vector<string> binaryTreePaths(TreeNode* root) {
      cur.clear(), ans.clear();
      pre(root);
      return ans;
    }
    void pre(TreeNode* root){
      if(!root) return ;
      cur.push_back(root->val);
      if(!root->left && !root->right){
        string curs;
        for(auto e: cur){
          curs+=to_string(e)+"->";
        }
        if(curs.size()>=2){
          curs.pop_back();
          curs.pop_back();
        }
        ans.push_back(curs);
      }
      pre(root->left);
      pre(root->right);
      cur.pop_back();
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
  cin>>t;
  for(int ti=1;ti<=t;ti++){
      //cin
      printf("Case #%d:\n", ti);
      //cout
  }
	return 0;
}

