#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
int a[maxn];
int main()
{
    ll n,k,p,x,y;
    while(cin>>n>>k>>p>>x>>y) {
        ll tot = x;
        for(int i = 0; i < k; i++) {
            cin>>a[i];
            tot -= a[i];
        }
        int left = n - k-1;
        vector<int> v;
        int d = 0;
        if(tot<=left)d = -1;
        int t = y;
        y = min(p,y);
        for(int i = k; d>=0&&i < n; i++)
        {
            if(tot-y>=left) {
                d = y;
                tot -= y;
            }
            else {
                tot--;
                d = 1;
            }
            a[i] = d;
            v.push_back(d);
            left--;
        }
        y = t;
        if(d>=0) {
            sort(a,a+n);
            if(a[n/2]<y)d = -1;
            else {
                for(auto e: v) cout<<e<<" ";
                cout<<endl;
            }
        }
        else puts("-1");
    }
    return 0;
}
