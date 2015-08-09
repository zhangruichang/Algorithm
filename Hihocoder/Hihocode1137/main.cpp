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
struct Node{
    string g;
    int s, v;
};
vector<int> ans, cur;
int maxvc, anssc, x, y, n, s;
Node v[maxn];

void dfs(int now, int xc, int yc, int sc, int vc){
    if(xc== x && yc== y){
        if(sc>s) return ;
        if(vc>maxvc){
            maxvc=vc;
            anssc=sc;
            ans=cur;
        }else if(vc==maxvc){
            if(ans.empty()) ans=cur;
            else{
                for(int i=0;i<ans.size();i++){
                    if(ans[i]==cur[i]) continue;
                    else if(ans[i]<cur[i]) break;
                    else{
                        ans=cur;
                        anssc=sc;
                        break;
                    }
                }
            }
        }
        return ;
    }
    if(xc > x || yc > y || sc> s) return ;
    dfs(now+1, xc, yc, sc, vc);
    cur.push_back(now);
    if(v[now].g=="M"){
        dfs(now+1, xc+1, yc, sc+v[now].s, vc+v[now].v);
    }else{
        dfs(now+1, xc, yc+1, sc+v[now].s, vc+v[now].v);
    }
    cur.pop_back();
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    cin>>n>>x>>y>>s;
    for(int i=0;i<n;i++){
        cin>>v[i].g>>v[i].v>>v[i].s;
    }
    ans.clear(), cur.clear();
    maxvc=anssc=INT_MIN;
    dfs(0, 0, 0, 0, 0);
    cout<<maxvc<<" "<<anssc<<endl;
    for(auto e: ans) cout<<e+1<<endl;
	return 0;
}
