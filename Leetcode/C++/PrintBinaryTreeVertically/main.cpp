/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<bits/stdc++.h>
#include "../structlib.h"
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)

class Solution{

public:
  vector<TreeNode*> PrintVertically(TreeNode* root){
    int order=1, width=0;
    queue<Node> q;
    vector<Node> v;
    q.push({width, order, root});
    while(!q.empty()){
      auto cur=q.front();q.pop();
      v.push_back(cur);
      if(cur.p->left) q.push({cur.width-1, cur.order+1, cur.p->left});
      if(cur.p->right) q.push({cur.width+1, cur.order+1, cur.p->right});
    }
    sort(v.begin(), v.end(), comp);
    vector<TreeNode*> ans;
    for(auto e: v){
      ans.push_back(e.p);
    }
    return ans;
  }

private:
  struct Node{
    int width, order;
    TreeNode* p;
  };

  static bool comp(Node n1, Node n2){
    if(n1.width!=n2.width) return n1.width<n2.width;
    return n1.order<n2.order;
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
