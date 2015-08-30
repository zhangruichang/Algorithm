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

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
      string ans;
      for(auto e: strs){
        unsigned int cur=e.size();
        for(int left=24;left>=0;left-=8){
          ans+=char(cur / (1<<left)-128);
          cur %= (unsigned int)(1<<left);
        }
        ans+=e;
      }
      return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
      vector<string> ans;
      int n=s.size();
      for(int i=0;i<n;){
        unsigned int len=0;
        for(int j=0;j<4;j++){
          len += (unsigned int)(s[i+j]+128) * (1<<(24-8*j));
        }
        ans.push_back(s.substr(i+4, len));
        i+=(len+4);
      }
      return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
  cout<<char(65)<<endl;
  cin>>t;
  for(int ti=1;ti<=t;ti++){
      //cin
      printf("Case #%d:\n", ti);
      //cout
  }
	return 0;
}
