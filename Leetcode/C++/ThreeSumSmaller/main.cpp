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
    int threeSumSmaller(vector<int>& nums, int x) {
      if(nums.empty()) return 0;
      sort(nums.begin(), nums.end());
      int ans=0, n = nums.size();
      for(int i=0;i<n;i++){
        int cur=nums[i];
        for(int j=i+1, k=n-1; j<k; ){
          if(cur+nums[j]+nums[k]>=x) k--;
          else ans+=k-j, j++;
        }
      }
      return ans;
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
