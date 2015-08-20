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
    int closestBST(TreeNode*root, double value){
        //assume INT_MIN not occur in tree
        if(!root) return INT_MIN;
        if(value==(double)(root->val)) return root->val;
        else if(value<(double)(root->val)){
            auto Left=closestBST(root->left, value);
            if(Left==INT_MIN) return root->val;
            if(abs((double)Left-value)<abs((double)(root->val)-value)) return Left;
            else return root->val;
        }else{
            auto Right=closestBST(root->right, value);
            if(Right==INT_MIN) return root->val;
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
