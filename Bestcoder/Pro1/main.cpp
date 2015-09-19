/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <iostream>
#include <cstdio>
#include <vector>
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
int a[1000+5], n, t, m, p;
int dp[1000+5][1000+5];
int mod=1e9+7;
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
      n=getint(), p=getint();
      for(int i=0;i<n;i++) a[i]=getint(), a[i]%=p;
      dp[0][0]=1;
      for(int j=1;j<p;j++) dp[0][j]=0;
      for(int i=1;i<=n;i++){
        for(int j=0;j<p;j++){
          dp[i][j]=(dp[i-1][(j+p-a[i-1])%p]+dp[i-1][j])%mod;
        }
      }
      cout<<dp[n][0]%mod<<endl;
  }
	return 0;
}
