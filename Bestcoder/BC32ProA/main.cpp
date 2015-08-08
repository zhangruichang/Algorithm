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
#include<fstream>
#include<iostream>
#include<algorithm>
//#include <unordered_set>
//#include <unordered_map>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
#define f first
#define s second
struct Node
{
    int first, second, index;
    Node(int a, int b, int c)
    {
        first=a;second=b;index=c;
    }
    bool operator<(Node d) const
    {
        if(first-second != d.first-d.second)
            return first-second> d.first-d.second;
        else if(second!=d.second)
            return second<d.second;
        else
            return index<d.index;
    }
};
vector<Node> v;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n, a, b;
    while(cin>>n)
    {
        v.clear();
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            Node n(a, b, i);
            v.push_back(n);
        }
        sort(v.begin(), v.end());
        if(n>=1) cout<<v[0].index;
        for(int i=1;i<n;i++) cout<<" "<<v[i].index;
        cout<<endl;
    }

	return 0;
}
