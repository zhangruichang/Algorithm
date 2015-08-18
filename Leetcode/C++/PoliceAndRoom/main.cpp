/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<bits/stdc++.h>
#include"../structlib.h"
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

class Solution{
private:
  int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};
  bool outrange(int i, int j){
    return i<0 || i>=m || j<0 || j>=n;
  }
  int m, n;
public:
  void policeAndRooms(vector<vector<int>>& rooms){
    m=rooms.size();
    if(!m) return;
    n=rooms[0].size();
    bool v[m][n];
    for(int i=0;i<m;i++)for(int j=0;j<n;j++){
      if(rooms[i][j]==-1 || rooms[i][j]==0) continue;
      memset(v, 0 ,sizeof v);
      queue<pii> q;
      q.push({i, j});
      int level=0;
      while(!q.empty()){
        int qs=q.size();
        for(int qi=0;qi<qs;qi++){
          auto cur=q.front();q.pop();
          if(rooms[cur.fi][cur.se]==0) {
            rooms[i][j]=level;
            goto L;
          }
          for(int k=0;k<4;k++){
            int nx=i+dx[k], ny=j+dy[k];
            if(outrange(nx, ny) || rooms[nx][ny]==-1 || v[nx][ny]) continue;
            q.push({nx, ny});
            v[nx][ny]=1;
          }
        }
        level++;
      }
    L:;
    }
  }
};

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/

	return 0;
}
