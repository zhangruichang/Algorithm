/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<bits/stdc++.h>
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


int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
  string s;
  cin>>s;
  int n=s.size();

  unordered_set<int> fum={1};
  int back2=1, back1=1,cur=2;
  while(cur<=100){
    cur=back2+back1;
    fum.insert(cur);
    back2=back1;
    back1=cur;
  }
  //for(auto e: fum) cout<<e<<" ";
  //cout<<endl;
  vector<string> v;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      string cur=s.substr(i, j-i+1);
      unordered_map<char, int> um;
      for(auto e :cur){
        um[e]++;
      }
      if(fum.count(um.size()))
        v.push_back(cur);
    }
  }
  sort(v.begin(), v.end());
  v.erase( unique(v.begin(), v.end()), v.end());
  for(auto e: v) cout<<e<<endl;
	return 0;
}
