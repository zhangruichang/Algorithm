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
  int hIndex(vector<int>& c) {
    int n = c.size();
    if(!n) return 0;
    int low = 0, high = c[n-1];
    while(low<=high){
      cout<<"["<<low<<" "<<high<<"]"<<endl;
      if(low == high) return low;
      if(low+1==high){
          int l = lower_bound(c.begin(), c.end(), high) - c.begin();
          if(n-l>=high) return high;
          return low;
      }
      int mid = (low+high) >> 1;
      int l = lower_bound(c.begin(), c.end(), mid)-c.begin();
      if(n-l>=mid) low=mid;
      else high=mid-1;
    }
  };
} S;

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
  vector<int> c={100};
  S.hIndex(c);
	return 0;
}
