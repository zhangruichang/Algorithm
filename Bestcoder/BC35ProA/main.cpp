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
LL GCD(LL m, LL n)
{
    if(!m) return n;
    return GCD(n%m, m);//yushu and chushu
}
int a[maxn], cnt, ttcnt;
vector<int> v;
LL n, m;
void dfs(int ni, int ti)//1 black, 0 white
{
    if(ti>=n+m)
    {
        if(ni==n)
        {
            for(int i=0;i+1<v.size();i++)
            {
                if(v[i]==0 && v[i+1]==1) cnt++;
                //cout<<v[i]<<" ";
            }
            //cout<<v[v.size()-1]<<endl;
            ttcnt++;
        }
        return ;
    }
    if(ni>=n+1) return ;
    v.push_back(1);
    dfs(ni+1, ti+1);//1 black
    v.back()=0;
    dfs(ni, ti+1);
    v.pop_back();
}
LL dp[13][13][2];
LL F(LL ni, LL mi, LL f)
{
    //cout<<ni<<" "<<mi<<endl;
    //if(ni>=n || mi>=m) return 0;
    if(!ni || !mi) return 0;
    if(ni==1 && mi==1 && f==0) return 1;
    if(dp[ni][mi][f]!=-1) return dp[ni][mi][f];
    if(f==0) return (dp[ni][mi][0]=(F(ni, mi-1, 1)+F(ni, mi-1, 0)));
    else return (dp[ni][mi][1]=(F(ni-1, mi, 1)+F(ni-1, mi, 0)));
}
LL C(int n, int m)
{
    LL fenzi=1, fenmu=1;
    for(LL i=m;i>=1;i--)
        fenmu*=(i+n), fenzi*=i;
    return fenmu/fenzi;
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>n>>m)
    {
        for(int i=0;i<13;i++) for(int j=0;j<13;j++) for(int k=0;k<2;k++) dp[i][j][k]=-1;
        LL cnt1=F(n, m, 0), cnt2=F(n, m, 1), cnt=cnt1+cnt2;
        cout<<cnt1<<" "<<cnt2<<" "<<cnt<<endl;
        cnt+=C(n-1, m-1);
        LL ttcnt=C(n,m );
        int gcd=GCD(cnt, ttcnt);
        cout<<cnt/gcd<<"/"<<ttcnt/gcd<<endl;
        /*
        time_t start=clock();
        cnt=ttcnt=0;v.clear();
        dfs(0, 0);
        int gcd=GCD(cnt, ttcnt);
        cout<<cnt/gcd<<"/"<<ttcnt/gcd<<endl;
        //cout<<runcnt<<endl;
        time_t end=clock();cout<<(end-start)/1000.0<<endl;*/
    }
	return 0;
}
