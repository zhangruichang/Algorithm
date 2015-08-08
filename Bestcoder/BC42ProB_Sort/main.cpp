/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <bits/stdc++.h>
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
int a[maxn], n, t, m;

struct Node1
{
    int x, y;
};
struct Node2
{
    int x, y, z;
};
Node1 h[maxn];
Node2 q[maxn];
bool comp0(Node1 n1, Node1 n2)
{
    if(n1.x!=n2.x) return n1.x<n2.x;
    else return n1.y<n2.y;
}
bool comp1(Node2 n1, Node2 n2)
{
    if(n1.x!=n2.x) return n1.x<n2.x;
    else return n1.y<n2.y;
}
bool comp2(Node2 n1, Node2 n2)
{
    return n1.y<n2.y;
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int x;
    while(n=getint())
    {
        m=getint();
        for(int i=0;i<n;i++) x=getint(), h[i]=(Node1){x, i+1};
        sort(h, h+n, comp0);
        for(int i=0;i<m;i++) x=getint(), q[i]=(Node2){x, i+1, 0};
        sort(q, q+m, comp1);
        for(int i=0, j=0; i<m && j<n; )
        {
            if(h[i].x<q[j].x) i++;
            else if(h[i].x>q[j].x) q[j++].z=-1;
            else q[j++].z=h[i].y, i++;
        }
        sort(q, q+m, comp2);
        for(int i=0;i<m;i++) printf("%d\n", q[i].z);
    }
	return 0;
}
