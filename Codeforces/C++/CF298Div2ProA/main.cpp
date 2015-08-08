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
#include <unordered_set>
#include <unordered_map>
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
    return !m ? n : GCD(n%m, m);
}


int a[maxn], n, t, m;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>n)
    {
        if(n==4) {cout<<"4\n2 4 1 3\n";continue;}
        int ai=0;
        for(int i=1;i<=n;i+=2) a[ai++]=i;
        for(int i=2;i<=n;i+=2)
        {
            if(abs(a[ai-1]-i)!=1)
                a[ai++]=i;
        }
        /*
        for(int i=3;i<=n;i+=3)
        {
            if(abs(a[ai-1]-i)!=1)
                a[ai++]=i;
        }*/
        cout<<ai<<endl;
        for(int i=0;i<ai;i++)
            cout<<a[i]<<" \n"[i==ai-1];
    }
	return 0;
}
