#include <stack>
#include <cstdio>
#include <list>
#include <cassert>
#include <set>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cctype>
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <string>
#include <map>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define Lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define PB push_back
#define X first
#define Y second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define LC rt << 1, l, mid
#define RC rt << 1|1, mid + 1, r
#define LRT rt << 1
#define RRT rt << 1|1
#define FOR(i, a, b) for (int i=(a); (i) < (b); (i)++)
#define FOOR(i, a, b) for (int i = (a); (i)<=(b); (i)++)
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 1e2+10;
const int MOD = 1e9;
const int dir[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
const int seed = 131;
int cases = 0;
typedef pair<int, int> pii;

vector<int> G[MAXN];
int pa[MAXN];

int find(int n)
{
    return pa[n] = (pa[n] == n ? n : find(pa[n]));
}

int main()
{
    //ROP;
    int n, m;
    cin >> n >> m;
    set<int> mp;
    bool flag = true;
    for(int i=1;i<=n;i++)
    {
        pa[i] = i;
        int num;
        cin >> num;
        if (num) flag = false;
        for(int j=0;j<num;j++)
        {
            int tmp;
            cin >> tmp;
            G[tmp].PB(i);
        }
    }
    for(i=1;i<=m;i++)
        for(int j=0;j<G[i].size();j++) for(int k=j+1;k<G[i].size();k++)
        {
            int u = G[i][j], v = G[i][k];
            int x = find(u), y = find(v);
            if (x != y) pa[x] = y;
        }
    for(int i=1;i<=n;i++) find(i);
    for(int i=1;i<=n;i++) mp.insert(pa[i]);
    printf("%d\n", flag ? SZ(mp) : SZ(mp)-1);
    return 0;
}
