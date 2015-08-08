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
//typedef vector<int> vi;
#define fi first
#define se second
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
int GCD(int m, int n)
{
    if(!m) return n;
    return GCD(n%m, m);//yushu and chushu
}
int a[maxn], n, t, m, cnt, ttcnt;
bool v[25];int vi;
void dfs(int ni, int ti)//1 black, 0 white
{
    if(ti>=n+m)
    {
        if(ni==n)
        {
            for(int i=0;i+1<vi;i++)
            {
                if(!v[i]&& v[i+1]) cnt++;
            }
            ttcnt++;
        }
        return ;
    }
    if(ni>=n+1) return ;
    v[vi++]=1;
    dfs(ni+1, ti+1);//1 black
    v[vi-1]=0;;
    dfs(ni, ti+1);
    vi--;
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        //time_t start=clock();
        vi=0;
        cnt=ttcnt=0;memset(v, 0 ,sizeof(v));
        dfs(0, 0);
        int gcd=GCD(cnt, ttcnt);
        cout<<cnt/gcd<<"/"<<ttcnt/gcd<<endl;
        //time_t end=clock();cout<<(end-start)/1000.0<<endl;
    }
    return 0;
}
