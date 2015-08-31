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

//first scan, when use variable, directly use in for loop, c1, c2, maxlen, and then start
//then third chars appear, I need last pos, so maintain lastpos in three if branches
class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int n=s.size();
    char c1=0, c2=0;
    int start = 0, maxlen=0, lastpos=-1;
    for(int i=0;i<n;i++){
        if(!c1 || c1==s[i]){
            c1=s[i];
            if(i && s[i]!=s[i-1]) lastpos =i;
        }else if(!c2 || c2==s[i]){
            c2=s[i];
            if(i && s[i]!=s[i-1]) lastpos =i;
        }else if(s[i]!=c1 && s[i]!=c2){
            maxlen=max(maxlen, i-start);
            start=lastpos;
            c1=s[lastpos];
            c2=s[i];
            lastpos = i;
        }
    }
    maxlen=max(maxlen, n-start);
    return maxlen;
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
