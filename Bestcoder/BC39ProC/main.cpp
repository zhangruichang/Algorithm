#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
const ll mod = 10007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
int cnt[maxn],a[maxn];
ll d[maxn];
int main()
{
        int n;
        while(~scanf("%d",&n))
        {
            int Mgcd = 1;
            for(int i = 0; i < n; i++) {
                int x;
                scanf("%d",&x);
                Mgcd = max(Mgcd,x);
                a[i] = x;
            }
            memset(cnt,0,sizeof(cnt[0])*Mgcd+20);
            for(int i = 0; i < n; i++)cnt[a[i]]++;
            ll ans = 0,res = 0;
            for(ll i = Mgcd; i > 0; i--)
            {
                ll tot = 0;
                for(ll j = i; j <= Mgcd; j+= i)
                {
                    tot += cnt[j];
                    d[i] = (d[i]-d[j]+mod)%mod;
                }
                d[i] = (d[i]+ tot*tot)%mod;
                ans = (ans+i*i*d[i]-i*d[i])%mod;
                //ans = (i*i*d[i]+mod)%mod;
                //res = (res+i*d[i])%mod;
            }
            //cout<<(ans-res+mod)%mod<<endl;
            cout<<ans%mod<<endl;
        }
        return 0;
}
