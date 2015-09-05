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
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)

class Solution {
public:
    int maxpath;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        maxpath=INT_MIN;
        maxpath1(root);
        return maxpath;
    }
    int max3(int x, int y, int z){
        return max(x, max(y,z));
    }
    int max5(int a1, int a2, int a3, int a4, int a5){
        return max3(max3(a1,a2,a3),a4,a5);
    }
    int maxpath1(TreeNode* root){
        if(!root) return 0;
        int leftmax=maxpath1(root->left), rightmax=maxpath1(root->right);
        maxpath=max5(maxpath, leftmax+root->val, rightmax+root->val, root->val, leftmax+rightmax+root->val);
        return max3(leftmax+root->val, rightmax+root->val, root->val);
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
