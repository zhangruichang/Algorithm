#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
string a[maxn],ans[maxn];
int main1()
{
    int n;
    while(cin>>n) {
        int cnt[2][26];
        memset(cnt,0,sizeof cnt);
        for(int i = 0; i < n; ++i) cin>>a[i],++cnt[0][a[i][0]-'A'];
        multiset<string> Q;
        for(int i = 0; i < n; ++i) {
            string x;
            cin>>x;
            ++cnt[1][x[0]-'A'];
            Q.insert(x);
        }
        sort(a,a+n);
        int cur = 0;
        for(int i = 0; i < n; ++i) {
            string & t = a[i];
            int id = t[0]-'A';
            for(multiset<string>::iterator it = Q.begin(); it != Q.end(); ++it) {
                const string & now = *it;
                int idx = now[0] - 'A';
                if(now[0]==t[0]) {
                    ans[cur++] = t + " " + now;
                    --cnt[0][id];
                    --cnt[1][idx];
                    Q.erase(it);
                    break;
                }else if(cnt[0][idx] < cnt[1][idx]&&cnt[0][id]>cnt[1][id]) {
                    ans[cur++] = t + " " + now;
                    --cnt[0][id];
                    --cnt[1][idx];
                    Q.erase(it);
                    break;
                }
            }
        }
        sort(ans,ans+cur);
        cout<<ans[0];
        for(int i = 1; i < cur; ++i) {
            cout<<", "<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
