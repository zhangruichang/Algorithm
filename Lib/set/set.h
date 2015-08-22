#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED
#include <iostream>
using namespace std;
class Set{
private:
  struct Node{
    int val;
    Node*left, *right;
    Node(int val_): val(val_), left(NULL), right(NULL){}
  };
  Node* root;
  Node* Insert(Node*& root, Node*& parent, int val){
      if(!root){
          if(!parent){
              root=new Node(val);
              return root;
          }else if(parent->val>val){
              parent->left=new Node(val);
              return parent->left;
          }else if(parent->val<val){
              parent->right=new Node(val);
              return parent->right;
          }
      }
      //if(root->val<val)
      if(root->val<val){
          return Insert(root->right, root, val);
      }else if(root->val>val){
          return Insert(root->left, root, val);
      }else;
          return root;
  }
  Node* Find(Node*root, int val){
    if(!root) return NULL;
    if(root->val<val){
        return Find(root->right, val);
    }else if(root->val>val){
        return Find(root->left, val);
    }else;
        return root;
  }
  Node* GetParent(Node* root, Node* parent, Node* p){
    if(!p || !root) return NULL;//NULL means parent not exist
    if(root==p) return parent;
    if(p->val < root->val) return GetParent(root->left,root, p);
    else if(p->val > root->val) return GetParent(root->right, root, p);
  }
  Node* FindLeftMax(Node* p){
    p=p->left;
    while(p && p->right){
      p=p->right;
    }
    return p;
  }
  Node* FindRightMin(Node* p){
    p=p->right;
    while(p && p->left){
      p=p->left;
    }
    return p;
  }
  void Delete(Node*& root, int val){
    Node* p=Find(root, val);
    if(!p) return ;
    if(!p->left && !p->right){
      Node* Parent = GetParent(root, NULL, p);
      if(!Parent) {root=NULL;return ;}
      else if(Parent->left == p){
        Parent->left=NULL;
      }else{
        Parent->right=NULL;
      }
    }else if(p->left){
      Node* LeftMax=FindLeftMax(p);
      p->val=LeftMax->val;
      Delete(root, LeftMax->val);
    }else{
      Node* RightMin=FindRightMin(p);
      p->val=RightMin->val;
      Delete(root, RightMin->val);
    }
  }
  void InOrder(Node* root){
    if(!root) return ;
    InOrder(root->left);
    cout<<root->val;
    InOrder(root->right);
  }
  Node* Lower_Bound(Node* root, int val){
    if(!root) return NULL;
    if(val == root->val) return root;
    else if(val < root->val){
      auto p=Lower_Bound(root->left, val);
      if(p) return p;
      else return root;
    }else {
      auto p=Lower_Bound(root->right,val);
      if(p) return p;
      else return NULL;
    }
  }

  Node* Upper_Bound(Node* root, int val){
    if(!root) return NULL;
    else if(val < root->val){
      auto p=Upper_Bound(root->left, val);
      if(p) return p;
      else return root;
    }else {
      auto p=Upper_Bound(root->right,val);
      if(p) return p;
      else return NULL;
    }
  }

public:
  void Insert(int val){
    Node* parent=NULL;
    Insert(root, parent, val);
  }
  void Delete(int val){
    Delete(root, val);
  }
  bool Find(int val){
    return Find(root, val);
  }
  void InOrder(){
    InOrder(root);
    cout<<endl;
  }
  int Lower_Bound(int val){
    auto p=Lower_Bound(root,val);
    if(!p) return INT_MAX;
    return p->val;
  }
  int Upper_Bound(int val){
    auto p=Upper_Bound(root,val);
    if(!p) return INT_MAX;
    return p->val;
  }
  Set(): root(NULL){
  }
};

#endif // SET_H_INCLUDED
