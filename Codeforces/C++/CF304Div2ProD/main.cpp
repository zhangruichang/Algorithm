/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 10;
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
int n, t, m, a1, b;
LL P[maxn];

/*
void Prime()
{
    memset(P, 0, sizeof P);//0 is Prime
    for(LL i=2;i*i<=(LL)5e6;i++)
    {
        if(!P[i])
        {
            for(LL j=i*i;j<=(LL)5e6;j+=i) P[j]=1;
        }
    }
    int ai=0;
    for(int i=2;i<=(LL)5e6;i++) if(!P[i]) a[ai++]=i;
    //for(int i=0;i<100;i++) cout<<a[i]<<" ";
}
*/
void F(LL n)//Print primes in [1..n]
{
    memset(P, 0, sizeof(P));
    vector<LL> ans;
    for(LL i=2;i<=n;i++)
    {
        if(!P[i]) ans.push_back(i), P[i]=1;
        for(int j=0;j<ans.size();j++)
        {
            LL t=i*ans[j];
            if(t>n) break;
            P[t]=P[i]+P[ans[j]];
            if(i%ans[j]==0) break;
        }
    }
    for(LL i=1;i<=n;i++) P[i]+=P[i-1];
    //fill(P, P+maxn, 1);
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
    F(maxn);
    while(cin>>t)
    {
        for(int ti=1;ti<=t;ti++)
        {
            cin>>a1>>b;
            cout<<P[a1]-P[b]<<endl;
        }
    }
	return 0;
}
