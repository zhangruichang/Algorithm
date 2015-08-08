#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
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
typedef pair<int, int> pii;
vector<int> f1, f2, f3;
int main()
{
    int n;
    while(cin>>n)
    {
        f1.clear(), f2.clear(), f3.clear();
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x==1) f1.push_back(i+1);
            else if(x==2) f2.push_back(i+1);
            else f3.push_back(i+1);
        }
        int minlen=min(f1.size(), min(f2.size(), f3.size()));
        cout<<minlen<<endl;
        for(int i=0;i<minlen;i++)
        {
            cout<<f1[i]<<" "<<f2[i]<<" "<<f3[i]<<endl;
        }
    }
	return 0;
}
