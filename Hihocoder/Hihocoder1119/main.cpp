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
int a[300][300], n, t, m, ttmcnt, ttnmcnt;
int dx[8]={-1, 0, 1, 1, 1, 0, -1, -1}, dy[8]={-1, -1, -1, 0, 1 ,1, 1, 0};
bool v[300][300];

bool outrange(int i, int j){
    return i<0 || i>=n || j<0 || j>=m;
}

void s1contains2(pair<set<pii>, int> p1, pair<set<pii>, int> p2){
    auto s1=p1.fi, s2=p2.fi;
    for(auto e: s2){
        if(!s1.count(e)) return ;
    }
    if( (p1.se-p2.se) != (s1.size()-s1.size()) ) return ;
    for(auto e: s1){
        if(!s2.count(e) && !v[e.fi][e.se]) ttmcnt++, v[e.fi][e.se]=1;
    }
}

pair<set<pii>, int> getminercnt(int i, int j){
    int mcnt=0;
    set<pii> s;
    for(int k=0;k<8;k++){
        int nx=i+dx[k], ny=j+dy[k];
        if(outrange(nx, ny)) continue;
        if(a[nx][ny]==-1) s.insert({nx, ny}), mcnt++;
    }
    return {s, mcnt};
}

void minercnt(int i, int j){
    int mcnt=0;
    for(int k=0;k<8;k++){
        int nx=i+dx[k], ny=j+dy[k];
        if(outrange(nx, ny)) continue;
        if(a[nx][ny]==-1) mcnt++;
    }
    if(!a[i][j]){
        for(int k=0;k<8;k++){
            int nx=i+dx[k], ny=j+dy[k];
            if(outrange(nx, ny)) continue;
            if(a[nx][ny]==-1 && !v[nx][ny]) v[nx][ny]=1, ttnmcnt++;
        }
    }else if(a[i][j]==mcnt){
        for(int k=0;k<8;k++){
            int nx=i+dx[k], ny=j+dy[k];
            if(outrange(nx, ny)) continue;
            if(a[nx][ny]==-1 && !v[nx][ny]) v[nx][ny]=1, ttmcnt++;
        }
    }

    /*
    for(int k=0;k<8;k++){
        int nx=i+dx[k], ny=j+dy[k];
        if(outrange(nx, ny)) continue;
        if(a[nx][ny]>=0){
            auto p1=getminercnt(i, j), p2=getminercnt(nx, ny);
            s1contains2(p1, p2);
        }
    }*/
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
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
        memset(v, 0, sizeof v);
        ttmcnt=ttnmcnt=0;

        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(a[i][j]>=0){
                minercnt(i, j);
            }
        }
        cout<<ttmcnt<<" "<<ttnmcnt<<endl;
    }
	return 0;
}
