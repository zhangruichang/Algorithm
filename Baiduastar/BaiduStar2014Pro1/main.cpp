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
const int maxn = 100 + 10;
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
int a[maxn][maxn], dp[maxn][maxn][2], n, t, m;
bool v[maxn][maxn][2];

//dp[i][j][0]: after up, right, max value it can get
//dp[i][j][1]: after down, right, max value it can get

//dp[i][j][0]=max{dp[i][j-1][0], dp[i][j-1][1], dp[i+1][j][0] }
//dp[i][j][1]=max{dp[i][j-1][0], dp[i][j-1][1], dp[i-1][j][1] }

int f(int i, int j, int k){
    if(i<0 || i>=m || j<0 || j>=n) return INT_MIN;
    if(v[i][j][k]) return dp[i][j][k];
    v[i][j][k]=1;
    if(k==0){
        return dp[i][j][0]=max(max(f(i, j-1, 0), f(i, j-1, 1)), f(i+1, j, 0))+a[i][j];
    }else{
        return dp[i][j][1]=max(max(f(i, j-1, 0), f(i, j-1, 1)), f(i-1, j, 1))+a[i][j];
    }

    /*
    if(j==0){
        if(i==0){
            if(k==0) return dp[i][j][0]=INT_MIN;
            else return dp[i][j][1]=a[i][j];
            //if(k==0) return dp[i][j][0]=max(f(i+1, j, 0)+a[i][j], a[i][j]);
            //else return dp[i][j][1]=a[i][j];
        } else if(i==m-1){
            if(k==0) return dp[i][j][0]=INT_MIN;
            else return dp[i][j][1]=f(i-1, j, 1)+a[i][j];
        } else{
            if(k==0) return dp[i][j][0]=INT_MIN;//f(i+1, j, 0)+a[i][j];
            else dp[i][j][1]=f(i-1, j, 1)+a[i][j];
        }
    }else{
        if(i==0){
            if(k==0) return dp[i][j][0]=max(max(f(i, j-1, 0), f(i, j-1, 1)), f(i+1, j, 0))+a[i][j];
            else return dp[i][j][1]=max(f(i, j-1, 0), f(i, j-1, 1))+a[i][j];//max(dp[i][j-1][0], dp[i][j-1][1]);
        } else if(i==m-1){
            if(k==0) return dp[i][j][0]=max(f(i, j-1, 0), f(i, j-1, 1))+a[i][j];//dp[i][j-1][0], dp[i][j-1][1]);
            else return dp[i][j][1]=max(max(f(i, j-1, 0), f(i, j-1, 1)), f(i-1, j, 1))+a[i][j];//dp[i][j-1][0], dp[i][j-1][1]), dp[i-1][j][1]);
        } else{
            if(k==0) return dp[i][j][0]=max(max(f(i, j-1, 0), f(i, j-1, 1)), f(i+1, j, 0))+a[i][j];//dp[i][j-1][0], dp[i][j-1][1]), dp[i+1][j][0]);
            else return dp[i][j][1]=max(max(f(i, j-1, 0), f(i, j-1, 1)), f(i-1, j, 1))+a[i][j];//dp[i][j-1][0], dp[i][j-1][1]), dp[i-1][j][1]);
        }
    }
    */
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>m>>n;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>a[i][j];
        memset(v, 0, sizeof v);
        memset(dp, 0, sizeof dp);
        v[0][0][0]=v[0][0][1]=1;
        dp[0][0][0]=INT_MIN;
        dp[0][0][1]=a[0][0];
        printf("Case #%d:\n%d\n", ti, max(f(0, n-1, 0), f(0, n-1, 1)));
    }
	return 0;
}
