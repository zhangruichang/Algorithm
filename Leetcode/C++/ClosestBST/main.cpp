#include <iostream>
#include <cmath>
using namespace std;
struct TreeNode{
  int val;
  TreeNode* left, *right;
  TreeNode(int val_):val(val_), left(NULL), right(NULL){}
};

class Solution{
  public:
    int closestBST(TreeNode*root, double value){
        if(!root) return 0;
        if(value==(double)(root->val)) return root->val;
        else if(value<(double)(root->val)){
            auto Left=closestBST(root->left, value);
            if(!Left) return root->val;
            if(abs((double)Left-value)<abs((double)(root->val)-value)) return Left;
            else return root->val;
        }else{
            auto Right=closestBST(root->right, value);
            if(!Right) return root->val;
            if(abs((double)Right-value)<abs((double)(root->val)-value)) return Right;
            else return root->val;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
