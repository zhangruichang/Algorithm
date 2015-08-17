#include <iostream>

using namespace std;

class Solution{
    TreeNode* NearestinBST(TreeNode*root, double value){
        if(!root) return NULL;
        if(value==root->value) return root;
        else if(value<root->value){
            auto Left=NearestinBST(root->left, value);
            if(!Left) return root;
            if(abs(Left->value-value)<abs(root->value-value) return Left;
            else return root;
        }else{
            auto Right=NearestinBST(root->right, value);
            if(!Right) return root;
            if(abs(Right->value-value)<abs(root->value-value) return Right;
            else return root;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
