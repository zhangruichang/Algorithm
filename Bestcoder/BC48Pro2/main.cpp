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
const int maxn = 1e5 + 10;
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

int n, t, m, ans, u, v;
vector<int> Edge[maxn];
int color[maxn];
int cnt[3];//cnt[0], cnt[1], cnt[2]

bool dfs(int cur, int c){
    color[cur]=c;
    cnt[c]++;
    for(auto i: Edge[cur]){
        if(color[i]){
            if(color[cur]==color[i]) return 0;
        }
        else if(!dfs(i, 3-c)) return 0;
    }
    return 1;
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    t=getint();
    while(t--){
        n=getint(), m=getint();
        //memset(a, 0 ,sizeof a);//0 means has connectinon
        for(int i=1;i<=n;i++) Edge[i].clear();
        memset(color, 0 ,sizeof color);
        memset(cnt, 0, sizeof cnt);
        for(int i=0;i<m;i++){
            u=getint(), v=getint();
            Edge[u].push_back(v);
            Edge[v].push_back(u);
        }
        bool ok=1;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(color[i]) continue;
            cnt[1]=cnt[2]=0;
            if(!dfs(i, 1)){
                ok=0;
                break;
            }
            ans+=max(cnt[1] , cnt[2]);
        }

        if(ok && n>1){
            if(ans==n) ans--;
            cout<<ans<<" "<<n-ans<<endl;
        }
        else puts("Poor wyh");
    }
	return 0;
}
