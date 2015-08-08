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
int n, t, m, x1, y1, x2, y2;
string str[500+10];
const int dx[4]={-1, 1, 0, 0}, dy[4]={0,0,-1, 1};

struct Node
{
    int x, y;
};
inline bool outrange(int& i, int& j)
{
    return i<0 || i>=m || j<0 || j>=n;
}
inline bool check(int& i, int& j)
{
    for(int k=0;k<4;k++)
    {
        int nx=i+dx[k], ny=j+dy[k];
        if(outrange(nx, ny)) continue;
        if(str[nx][ny]=='.') {return 1;}
    }
    return 0;
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
    while(cin>>m>>n)
    {
        for(int i=0;i<m;i++) cin>>str[i];
        cin>>x1>>y1>>x2>>y2;
        x1--,y1--, x2--, y2--;
        if(x1==x2 && y1==y2 && check(x1, y1)) {puts("YES");continue;}
        queue<Node> q;
        q.push({x1, y1});
        bool ok=0;
        while(!q.empty())
        {
            auto cur=q.front();q.pop();
            //cout<<cur.x<<" "<<cur.y<<"    ";
            for(int k=0;k<4;k++)
            {
                int nx=cur.x+dx[k], ny=cur.y+dy[k];
                if(outrange(nx, ny)) continue;
                if((nx==x2 && ny==y2) && (str[x2][y2]=='X' || check(x2, y2)))
                {
                    //cout<<"cur: "<<nx<<" "<<ny<<str[x2][y2]<<" "<<check(x2, y2)<<endl;
                    ok=1;goto L1;
                }
                //if(cur.x==x2 && cur.y==y2) {ok=1;goto L1;}
                if(str[nx][ny]=='X') continue;
                str[nx][ny]='X';
                q.push({nx, ny});
            }
        }
     L1:puts(ok?"YES":"NO");
    }
	return 0;
}
