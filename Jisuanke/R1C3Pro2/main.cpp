/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 400;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)
int getint(){
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n)
{
    return !m ? n : GCD(n%m, m);
}
template <typename T>
string to_string(T value)
{
  //create an output string stream
  ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}
LL MultMod(LL a,LL b,LL MOD)
{
    a %= MOD;
    b %= MOD;
    LL ret = 0;
    while(b){
        if (b & 1){
            ret += a;
            if(ret >= MOD) ret -= MOD;
        }
        a = a << 1;
        if (a >= MOD) a -= MOD;
        b = b >> 1;
    }
    return ret;
}
LL a[maxn],  s[maxn][maxn], n, t, m, l, r;
bool dp[maxn][maxn];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    scanf("%lld%lld", &n, &m);
    for(LL i=1;i<=n;i++) scanf("%lld", &a[i]);
    for(int i=1;i<=n;i++) dp[i][i]=1;
    for(int i=1;i+1<=n;i++)   dp[i][i+1]=(a[i]==a[i+1]);
    for(LL l=3;l<=n;l++){
        for(LL i=1;i<=n;i++){
            LL j=i+l-1;
            dp[i][j]=(dp[i+1][j-1] && a[i]==a[j]);
        }
    }
    for(LL i=1;i<=n;i++){
        LL sum=0;
        for(LL j=i;j<=n;j++){
            sum+=a[j];
            s[i][j]=sum;
        }
    }
    //for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) cout<<dp[i][j]<<" \n"[j==n];
    //for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) cout<<s[i][j]<<" \n"[j==n];
    for(LL i=1;i<=m;i++){
        scanf("%lld%lld", &l, &r);
        LL sum=0;
        for(LL j=l;j<=r;j++){
            for(LL k=j;k<=r;k++){
                sum+=(dp[j][k] * s[j][k]);
            }
        }
        cout<<sum<<endl;
    }
	return 0;
}
