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
int a[maxn], t, m;
bool comp(pii p1, pii p2){
  return p1.fi>p2.fi;
}
int n, s;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
  cin>>n>>s;
  string str;int p, q;
  unordered_map<int, int> um1, um2;
  for(int i=0;i<n;i++){
    cin>>str>>p>>q;
    if(str=="B") um1[p]+=q;
    else um2[p]+=q;
  }

  vector<pii> v1;
  for(auto e: um1){
    v1.push_back({e.fi, e.se});
  }
  sort(v1.begin(), v1.end(), comp);

  vector<pii> v2;
  for(auto e: um2){
    v2.push_back({e.fi, e.se});
  }
  sort(v2.begin(), v2.end(), comp);


  if(v2.size()<s){
    for(auto e: v2){
      cout<<"S "<<e.fi<<" "<<e.se<<endl;
    }
  }else{
    int n=v2.size();
    for(int i=n-s;i<n;i++){
      pii e=v2[i];
      cout<<"S "<<e.fi<<" "<<e.se<<endl;
    }
  }

  for(int i=0;i<min((int)v1.size(), s);i++){
    pii e=v1[i];
    cout<<"B "<<e.fi<<" "<<e.se<<endl;
  }




	return 0;
}
