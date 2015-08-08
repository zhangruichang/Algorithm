/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
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
const int maxn=1010;
int a[maxn][maxn], price[maxn][maxn], n, t, m;
int dist[maxn], minprice[maxn];
bool v[maxn];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(~scanf("%d%d", &n, &m) && n!=0)
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            a[i][j]=price[i][j]=inf;
        for(int i=0;i<m;i++)
        {
            int u,v,dis,c;
            u=getint(), v=getint(), dis=getint(), c=getint();
            if(dis<a[u][v] || dis==a[u][v] && c<price[u][v])
                a[u][v]=a[v][u]=dis,price[u][v]=price[v][u]=c;
        }
        int s,t;
        scanf("%d%d", &s, &t);
        memset(v, 0 ,sizeof v);
        for(int j=1;j<=n;j++) dist[j]=a[s][j], minprice[j]=price[s][j];
        v[s]=1;
        for(int i=1;i<n;i++)
        {
            int mindis=inf, minprice1=inf, mini=-1;
            for(int j=1;j<=n;j++)
            {
                if(v[j]) continue;
                if(dist[j]<mindis
                   || (dist[j]==mindis && minprice[j] < minprice1))
                {
                    mindis=dist[j];
                    minprice1=minprice[j];
                    mini=j;
                }
            }
            if(mini==-1) break;
            v[mini]=1;
            for(int j=1;j<=n;j++)
            {
                if(v[j]) continue;
                if(dist[mini] + a[mini][j] < dist[j]
                   || (dist[mini] + a[mini][j] == dist[j] && minprice[mini] + price[mini][j] < minprice[j]))
                    dist[j] = dist[mini] + a[mini][j],
                    minprice[j] = minprice[mini] + price[mini][j];
            }
        }
        cout<<dist[t]<<" "<<minprice[t]<<endl;
    }
	return 0;
}
