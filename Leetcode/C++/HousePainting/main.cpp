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
const int maxn = 1e6 + 10;
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
int a[maxn], n, t, m;

class Solution
{
public:
    int HousePaint(vector<vector<int>> v){
        int n=v.size();
        if(!n) return 0;
        int dp[n][3];
        for(int j=0;j<3;j++){
            dp[0][j]=v[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                dp[i][j]=INT_MAX;
                for(int k=1;k<=2;k++){
                    dp[i][j]=min(dp[i][j], dp[i-1][(j+k)%3] + v[i][j]);
                }
            }
        }
        return min( min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
    }
} S;


int main()
{

#ifndef ONLINE_JUDGE
    //freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif

    //vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    //cout<<S.HousePaint(v)<<endl;
    srand (time(NULL));
    //unordered_set<int> us;
    for(int i=0;i<=100;){
        int len=i;
        cout<<"[";
        for(int i=0;i<len;i++){
            if(i) cout<<",";
            cout<<"[";
            for(int j=0;j<3;j++){
                if(!j){
                    cout<<rand()%20+1;
                }else{
                    cout<<","<<rand()%20+1;
                }
            }
            cout<<"]";
        }
        cout<<"]"<<endl;;
        i++;
    }
	return 0;
}
