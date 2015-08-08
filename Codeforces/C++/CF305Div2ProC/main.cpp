/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <bits/stdc++.h>
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
LL MultMod(LL a,LL b,LL MOD)
{
    a %= MOD;
    b %= MOD;
    LL ret = 0;
    while(b){
        if (b & 1){
            ret += a;
            if(ret >= MOD) ret -= MOD;
        }
        a = a << 1;
        if (a >= MOD) a -= MOD;
        b = b >> 1;
    }
    return ret;
}

long long inv(long long a,long long m){
	if(a == 1)return 1;
	return inv(m%a,m)*(m-m/a)%m;
}
LL n, t, m;

LL h1,a1,x1,y1,h2,a2,x2,y2;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/

    while(~scanf("%d", &m))
    {
        //time_t start=clock();
        //unordered_set<int> um1, um2;
        h1=getint(), a1=getint(), x1=getint(), y1=getint(), h2=getint(), a2=getint(), x2=getint(), y2=getint();
        //cin>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
        //LL cnt=0;
        LL r=m+10, ans1=-1;
        for(int i=1;i<=r;i++)
        {
            //h1=(MultMod(x1, h1, m)+y1)%m;
            h1=(x1*h1+y1)%m;
            if(h1==a1)
            {
                ans1=i;
                break;
            }
        }
        if(ans1==-1) {puts("-1");continue;}
        LL ans2=-1;
        for(int i=1;i<=r;i++)
        {
            //h2=(MultMod(x2, h2, m)+y2)%m;
            h2=(x2*h2+y2)%m;
            if(h2==a2)
            {
                ans2=i;
                break;
            }
        }
        if(ans2==-1) {puts("-1");continue;}
        for(int i=1;i<=r;i++)
        {
            h1=(x1*h1+y1)%m;
            if(h1==a1)
            {
                ans1=i;
                break;
            }
        }
        for(int i=1;i<=r;i++)
        {
            h2=(x2*h2+y2)%m;
            if(h2==a2)
            {
                ans2=i;
                break;
            }
        }
        //cout<<ans1<<" "<<ans2<<endl;
        if(ans1!=-1 && ans2!=-1)
            printf("%d\n", (ans1*ans2/GCD(ans1, ans2)) % m);
            //cout<<ans1*ans2/GCD(ans1, ans2)<<endl;
            //printf("%d\n", MultMod(    MultMod(ans1, ans2, m), inv(GCD(ans1, ans2),m), m)   );
        else puts("-1");
    }
	return 0;
}
