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
int a[maxn], b[maxn], n, t, m;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    n=getint();
    for(int i=0;i<n;i++) a[i]=getint();
    sort(a, a+n);
    n=unique(a, a+n)-a;
    for(int j=1;j<=1e6;j++){
        int index=lower_bound(a, a+n, j)-a;//max ai < j, if not, return 0
        index--;
        if(index<0) b[j]=0;
        else b[j]=a[index];
    }
    //for(int i=1;i<=10;i++) cout<<b[i]<<" ";
    //cout<<endl;
    int maxx=*max_element(a, a+n);
    int ans=0;
    for(int i=0;i<n;i++){
        //cout<<i<<": "<<endl;
        for(int k=1;k*a[i]<=(maxx+a[i]);k++){
            int res;
            if(k*a[i]<=1e6) res=b[k*a[i]];
            else res=maxx;
            //cout<<res<<" "<<a[i]<<endl;
            if(res<a[i]) continue;
            ans=max(ans, res%a[i]);
        }
    }
    cout<<ans<<endl;
	return 0;
}
