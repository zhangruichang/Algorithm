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

//https://www.hackerrank.com/challenges/maximise-sum

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
LL a[maxn], pre[maxn], n, t, m;


int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(LL i=0;i<n;i++) scanf("%lld", &a[i]);
        pre[0]=0;
        for(LL i=1;i<=n;i++) pre[i]=(pre[i-1]+a[i-1])%m;
        set<LL> s;
        LL ans=0;
        for(LL i=1;i<=n;i++)
        {
            auto it=s.upper_bound(pre[i]);
            if(it==s.end())
                ans=max(pre[i], ans);
            else
                ans=max( (pre[i]-*it+m)%m, ans);
            s.insert(pre[i]);
        }
        cout<<ans<<endl;
    }
	return 0;
}
