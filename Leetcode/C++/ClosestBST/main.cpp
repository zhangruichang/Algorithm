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
    TreeNode* closestBST(TreeNode*root, double value){
        if(!root) return NULL;
        if(value==(double)(root->val)) return root;
        else if(value<(double)(root->val)){
            auto Left=closestBST(root->left, value);
            if(!Left) return root;
            if(abs((double)(Left->val)-value)<abs((double)(root->val)-value)) return Left;
            else return root;
        }else{
            auto Right=closestBST(root->right, value);
            if(!Right) return root;
            if(abs((double)(Right->val)-value)<abs((double)(root->val)-value)) return Right;
            else return root;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
