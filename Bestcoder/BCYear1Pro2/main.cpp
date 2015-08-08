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
//int a[maxn], n, t, m;
int si, sn, tn;
string s, t="anniversary";

bool dfs(int si, int ti, int subcnt){
    if(subcnt==3){
        return si<=sn && ti==tn;
    }
    if(si>=sn || ti>=tn) return 0;
    for(int i=si;i<sn;i++){
        if(s[i]==t[ti]){
            int ei=i, eti=ti;
            while(ei<sn && eti<tn && s[ei]==t[eti]){
                if(dfs(ei+1, eti+1, subcnt+1)) return 1;
                ei++, eti++;
            }
        }
    }
    return 0;
}

int main() {
  /*
  #ifndef ONLINE_JUDGE
      freopen ("in.txt" , "r" , stdin);
      freopen ("out.txt" , "w" , stdout);
  #endif
  */
  int T, sn, tn;
  string s;
  cin>>T;

  while(T--) {
    cin>>s;
    sn=s.size();
    tn=t.size();
    int ss1, ts1, ss2, ts2, ss3, ts3, k;
    for(ss1=0, ts1=0; ss1<sn && ts1< tn && s[ss1]==t[ts1]; ss1++, ts1++);
    for(ss3=sn-1, ts3=tn-1; ss3>=0 && ts3>=0 && s[ss3]==t[ts3]; ss3--, ts3--);
    //[ss1, ss3], [ts1, ts3]
    for(ss2=ss1, ts2=ts1, k=0; ss2<=ss3 && ts2<=ts3;){
      if(s[ss2+k]==t[ts2]){
        k++; ts2++;
      }else{
        ts2=ts1, k=0, ss2++;
      }
    }
    puts(ts2>ts3? "YES" : "NO");
  }
  return 0;
}
