#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
struct TreeNode{
  int val;
  TreeNode* left, *right;
  TreeNode(int val_):val(val_), left(NULL), right(NULL){}
};

class Solution{
  public:
    TreeNode* dfs(TreeNode*root, double value){
        if(!root) return nullptr;
        if(value==(double)(root->val)) return root;
        else if(value<(double)(root->val)){
            auto Left=dfs(root->left, value);
            if(!Left) return root;
            if(abs((double)Left->val-value)<abs((double)(root->val)-value)) return Left;
            else return root;
        }else{
            auto Right=dfs(root->right, value);
            if(!Right) return root;
            if(abs((double)Right->val-value)<abs((double)(root->val)-value)) return Right;
            else return root;
        }
    }
    int closestBST(TreeNode* root, double value){
      return dfs(root, value)->val;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
