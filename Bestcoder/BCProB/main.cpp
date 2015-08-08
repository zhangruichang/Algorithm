/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
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
#include <sstream>
#include<algorithm>
using namespace std;
const int maxn = 1e6 + 10;
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

int n, t, m;
struct Node
{
    int x;
    bool operator<(Node n) const
    {
        return x>n.x;
    }
    Node(int x_): x(x_)
    {}
};
map<int, queue<int> > myset;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int x,q;
    while(n=getint())
    {
        m=getint();
    myset.clear();
    for(int i=0;i<n;i++)
    {
        x=getint();
        //Node nd(i+1);
        myset[x].push(i+1);
    }
    for(int i=0;i<m;i++)
    {
        q=getint();
        map<int, queue<int> >:: iterator it=myset.find(q);
        if(it==myset.end()) puts("-1");
        else if(it->second.empty()) puts("-1");
        else
        {
            printf("%d\n", it->second.front());
            it->second.pop();
        }
    }
    }
	return 0;
}
