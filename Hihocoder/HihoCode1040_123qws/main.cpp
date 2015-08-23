#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <sstream>
using namespace std;

#define DB(x) cerr<<#x<<"="<<x<<" "
#define DBN(x) cerr<<#x<<"="<<x<<"\n"
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define sqr(x) ((x)*(x))
#define sz(x) ((int)(x).size())
#define clr(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define mp make_pair

#define lson x+x,l,y
#define rson x+x+1,y+1,r

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<long long, long long> PLL;

#define INF 1000000000
#define EPS (double)1e-9
#define MOD 1000000007
#define PI 3.14159265358979328462
int x1[4], y1[4], x2[4], y2[4];
#define X first
#define Y second
int main(int argc, char *argv[])
{
    int T; cin >> T;
    while (T--) {
        for (int i = 0; i < 4; i++)
            cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        map<pair<int, int>, int > m;
        map<pair<int, int>, int >::iterator it;
        bool succ = true;
        for (int i = 0; i < 4; i++) {
            if (x1[i] == x2[i] && y1[i] == y2[i]) succ = false;
            m[mp(x2[i], y2[i])]++;
            m[mp(x1[i], y1[i])]++;
        }
        if (m.size() != 4) succ = false;
        for(it=m.begin();it!= m.end();it++) {
            if (it->second != 2) succ = false;
            int i;
            int xx1, yy1, xx2, yy2;
            for (i = 0; i < 4; i++)
                if (x1[i] == it->X.X && y1[i] == it->X.Y) {
                    xx1 = x2[i]; yy1 = y2[i]; break;
                }
                else if (x2[i] == it->X.X && y2[i] == it->X.Y) {
                    xx1 = x1[i]; yy1 = y1[i];break;
                }

            for (; i < 4; i++)
                if (x1[i] == it->X.X && y1[i] == it->X.Y) {
                    xx2 = x2[i]; yy2 = y2[i];
                }
                else if (x2[i] == it->X.X && y2[i] == it->X.Y) {
                    xx2 = x1[i]; yy2 = y1[i];
                }
            xx1 -= it->X.X; yy1 -= it->X.Y;
            xx2 -= it->X.X; yy2 -= it->X.Y;
            if (xx1 == yy1 && xx2 == yy2) succ = false;
            if (xx1*xx2 + yy1*yy2 != 0) succ = false;
        }

        if (succ) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}

