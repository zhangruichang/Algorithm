struct TreeNode{
  int val;
  TreeNode*left, *right;
};

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int val_) : val(val_), next(NULL){}
};

struct Interval{
  int start, end;
};
