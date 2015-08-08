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
LL sum[maxn];
int main()
{

#ifndef ONLINE_JUDGE
    //freopen ("in.txt" , "r" , stdin);
    //freopen ("out.txt" , "w" , stdout);
#endif

    LL a, b, n, l, t, m, L;
    while(cin>>a>>b>>n)
    {
        sum[0]=0;//sumi: A+...+A+(i-1)B
        for(int i=1;i<=maxn;i++) sum[i]=sum[i-1]+a+(i-1)*b;
        for(int i=0;i<n;i++)
        {
            cin>>L>>t>>m;
            int l=L,r=maxn;
            int ans=-1;
            while(l<=r)
            {
                if(l+1==r || l==r)
                {
                    //cout<<"l r:"<<l<<" "<<r<<endl;
                    if(t>=a+(r-1)*b && sum[r]-sum[L-1]<=t*m) ans=r;
                    else if(t>=a+(l-1)*b && sum[l]-sum[L-1]<=t*m) ans=l;
                    break;
                }
                int mid=(l+r)/2;
                if(t>=a+(mid-1)*b && sum[mid]-sum[L-1]<=t*m) l=mid;
                else r=mid-1;
            }
            cout<<ans<<endl;
        }
    }
	return 0;
}
