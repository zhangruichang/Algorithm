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

class Solution {
public:
    int partition(vector<int> nums, int low, int high){
        int i=low, j=high, pivot = nums[low];
        while(i<j){
            while(i<j && nums[j]>=pivot) j--;;
            while(i<j && nums[i]<=pivot) i++;
            if(i<j) swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[i]);
        return i;
    }
    int qs(vector<int> nums, int low, int high, int k){
        int mid = partition(nums, low, high);
        int order = mid-low+1;
        if(order==k) return nums[mid];
        else if(order>k) return qs(nums,low, mid-1, k);
        else return qs(nums, mid+1, high, k-order);
    }
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        if(!n) return ;
        qs(nums, 0, n-1, n/2);
        vector<int> v;
        for(int i=0, j=n/2+1;i<n && i<j && j<n;i++,j++){
            v.push_back(nums[i]);
            v.push_back(nums[j]);
        }
        nums=v;
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
  cin>>t;
  for(int ti=1;ti<=t;ti++){
      //cin
      printf("Case #%d:\n", ti);
      //cout
  }
	return 0;
}
