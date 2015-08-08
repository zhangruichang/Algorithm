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
#include<sstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 2e5 + 10;
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
template <typename T>
string to_string(T value)
{
  //create an output string stream
  ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}
vector<int> a[maxn];
int n, t, m, x;
vector<int> cur, ans;
bool dfs(int now, int num)
{
    if(now>=n) {if(ans.empty()) ans=cur;return 1;}
    for(int i=0;3*i<=num;i++)
    {
        int index=num-3*i;
        if(!a[index].empty())
        {
            int x=a[index].back();
            cur.push_back(x);
            a[index].pop_back();
            if(dfs(now+1, num-3*i+1)) return 1;
            a[index].push_back(x);
            cur.pop_back();
        }
    }
    return 0;
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/

        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d", &x), a[x].push_back(i);
        /*
        cur.clear();ans.clear();
        if(dfs(0, 0))
        {
            puts("Possible");
            for(auto e: ans) cout<<e<<" ";
            cout<<endl;
        }
        else puts("Impossible");*/
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            while(cnt>=0 && a[cnt].size()==0) cnt-=3;
            if(cnt<0) {puts("Impossible");return 0;}
            ans.push_back(a[cnt].back());
            a[cnt].pop_back();
            cnt++;
        }
        puts("Possible");
        for(auto e: ans) cout<<e<<" ";
        cout<<endl;
    //}
	return 0;
}
