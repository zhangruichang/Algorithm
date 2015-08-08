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
LL a[27], n, t, m;
bool Check(string s)//1 means BC55, 0 means R23C31
{
    int i=0, n=s.size();
    while(i<n && isalpha(s[i])) i++;
    while(i<n && isdigit(s[i])) i++;
    return i==n;
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    string str;LL k;
    cin>>str>>k;LL maxc=0;
    for(int i=0;i<26;i++) cin>>a[i], maxc=max(maxc, a[i]);
    LL n=str.size();LL sum=0;
    for(auto e: str) sum+=a[e-'a'];
    LL ans=0;
    for(int i=0;i<n;i++) ans+=(i+1)*a[str[i]-'a'];
    ans+=(n+1+n+k)*k/2*maxc;
    cout<<ans<<endl;
	return 0;
}
