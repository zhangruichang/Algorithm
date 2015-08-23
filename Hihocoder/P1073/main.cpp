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
//#include<fstream>
#include<iostream>
#include<algorithm>
//#include <unordered_set>
//#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
int bitcount(int x) {//O(cnt), cnt is 1 number of x
    int res = 0;
    while (x) {
	res++;
	x -= x & -x;
    }
    return res;
}
struct Node
{
    string sno;
    int score;
    int rank;
    bool operator<(Node n) const
    {
        if(score!=n.score) return score>n.score;
        else return rank<n.rank;
    }
};
int t, n;
Node a[maxn];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    cin>>t;int ti=1;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i].sno>>a[i].score, a[i].rank=i;
        sort(a, a+n);
        /*for(int i=0;i<n;i++)
        {
            if(a[i].score==a[i-1].score) a[i].rank=a[i-1].rank;
        }*/
        cout<<"Case "<<ti++<<":"<<endl;
        int last=1;
        for(int i=0;i<n;i++)
        {
            if(!i || a[i].score!=a[i-1].score) cout<<i+1, last=i+1;
            else cout<<last;

            //cout<<r++<<;
            cout<<" "<<a[i].sno<<" "<<a[i].score<<endl;
        }
    }

	return 0;
}
