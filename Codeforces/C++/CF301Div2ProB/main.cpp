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
int a[maxn], n, t, m, k, p, x, y;
bool ok=0;
// 1 0 5 5 5
vector<int> cur, ans;
void dfs(int i, int sum)
{
    if(sum>x) return ;
    if(i==n)
    {
        if(sum<=x)
        {
            vector<int> tmp=cur;
            sort(tmp.begin() ,tmp.end());
            //for(auto e: tmp) cout<<e<<" ";
            //cout<<"n: "<<n<<"tmpsize: "<<tmp.size();
            if(tmp[(n+1)/2-1]>=y) /*cout<<"tmp: "<<tmp[(n+1)/2],*/ ok=1, ans=cur;
        }
        return ;
    }
    if(x-sum>(n-i)*p || x-sum<(n-i)) return ;
    //cout<<i<<" "<<sum<<endl;
    for(int j=1;j<=p;j++)
    {
        if( (sum+j>x) || ((x-(sum+j))>(n-i-1)*p) || ((x-(sum+j))<(n-i-1))) continue;
        cur.push_back(j);
        dfs(i+1, sum+j);
        cur.pop_back();
    }
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    iOS;
    int x1;
    cin>>n>>k>>p>>x>>y;
    int cursum=0;cur.clear();
    vector<int> v;
    for(int i=0;i<k;i++) cin>>x1,cur.push_back(x1),cursum+=x1;
    x-=cursum;
    if(x<n-k) puts("-1");
    else
    {
        for(int i=k;i<n;i++)
        {
            int tmp=min(y, x-(n-i-1));
            cur.push_back(tmp), v.push_back(tmp), x-=tmp;
        }
        sort(cur.begin(), cur.end());
        if(cur[n/2]>=y)
        {
            for(auto e: v) cout<<e<<" ";
            cout<<endl;
        }
        else puts("-1");
    }
	return 0;
}
