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
LL n, t, m;
string a, b, c;
LL ac[27],bc[27],cc[27];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>a>>b>>c)
    {

    memset(ac, 0, sizeof ac);
    memset(bc, 0, sizeof bc);
    memset(cc, 0, sizeof cc);
    for(auto e: a) ac[e-'a']++;
    for(auto e: b) bc[e-'a']++;
    for(auto e: c) cc[e-'a']++;
    LL maxans=0, maxi=0, maxci=0;
    for(LL i=100000;i>=0;i--)
    {
        bool sat=1;
        for(LL j=0;j<26;j++)
            if(bc[j]*i>ac[j]) {sat=0;break;}
        if(!sat) continue;
        LL ci=INT_MAX;
        for(LL j=0;j<26;j++)
        {
            if(!cc[j]) continue;
            ci=min((ac[j]-i*bc[j])/cc[j], ci);
        }
        if(i+ci>maxans)
        {
            maxans=i+ci;
            maxi=i;maxci=ci;
        }
    }
    for(LL i=0;i<maxi;i++) cout<<b;
    for(LL i=0;i<maxci;i++) cout<<c;
    for(LL i=0;i<26;i++)
    {
        ac[i]-=((LL)maxi*bc[i]+(LL)maxci*cc[i]);
    }
    for(LL i=0;i<26;i++)
    {
        for(LL j=0;j<ac[i];j++) cout<<char(i+'a');
    }
    cout<<endl;
    }
	return 0;
}
