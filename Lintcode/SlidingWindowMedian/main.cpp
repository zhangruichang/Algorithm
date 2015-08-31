/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<bits/stdc++.h>
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

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
      if(nums.size() == 0 || k== 0) return {};
      vector<int> ans;
      int n=nums.size();
      for(int i=0;i+k-1<n;i++){
        vector<int> cur(nums.begin()+i, nums.begin()+i+k);
        ans.push_back(qs(cur, 0, k-1, (k+1)/2));
      }
      return ans;
    }
    int partition(vector<int>& num, int s, int e){
      int i = s, j = e, pivot=num[s];
      while(i<j){
        while(i<j && num[j] >= pivot) j--;
        while(i<j && num[i] <=pivot) i++;
        if(i<j) swap(num[i], num[j]);
      }
      swap(num[s], num[i]);
      return i;
    }
    int qs(vector<int>& num, int s, int e, int k){
      int mid=partition(num, s, e);
      int order=mid-s+1;
      if( order == k) return num[mid];
      else if(order > k)
        return qs(num, s, mid-1, k);
      else return qs(num, mid+1, e, k-order);
    }
} S;



int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
  vector<int> num={1,2,7,8};
  int k=3;
  auto ans = S.medianSlidingWindow(num, k);
  for(auto e : ans){
    cout<<e<<" ";
  }
  cout<<endl;
	return 0;
}
