#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

int n_, k_;
vector<int> cur;
vector<vector<int> > ans, perans;
void dfs(int ni, int ki);
void per(int i);

vector<vector<int> > Permutation(int n, int k)
{
    n_=n, k_=k;
    cur.clear(), ans.clear();
    dfs(1, 0);
    perans.clear();
    for(auto i: ans)
    {
        cur=i;
        per(1);
    }
    return perans;
}
void per(int i)
{
    if(i>k_)
        perans.push_back(cur);
    else
    {
        for(int j=i;j<=k_;j++)
        {
            swap(cur[i-1],cur[j-1]);
            per(i+1);
            swap(cur[i-1],cur[j-1]);
        }
    }
}
void dfs(int ni, int ki)
{
    if(ki==k_)
    {
        ans.push_back(cur);
        return ;
    }
    if(ni>n_) return ;
    dfs(ni+1, ki);
    cur.push_back(ni);
    dfs(ni+1, ki+1);
    cur.pop_back();
}
void dfs_per(int ni, int ki);
vector<vector<int> > Permutation_dfs(int n, int k)
{
    cur.clear();for(int i=1;i<=n;i++) cur.push_back(i);
    ans.clear();
    k_=k, n_=n;
    dfs_per(1,0);
    return ans;
}
void dfs_per(int ni, int ki)
{
    if(ki==k_)
    {
        vector<int> prefix=cur;
        prefix.resize(k_);
        ans.push_back(prefix);
        return ;
    }
    for(int i=ni;i<=n_;i++)
    {
        swap(cur[ni-1], cur[i-1]);
        dfs_per(ni+1, ki+1);
        swap(cur[ni-1], cur[i-1]);
    }
}

int main()
{
    int n=6, k=3;
    auto ans=Permutation_dfs(n,k);
    cout<<ans.size()<<endl;
    for(auto i: ans)
    {
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
