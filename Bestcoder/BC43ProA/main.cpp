/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <iostream>
#include <vector>
#include <string>
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

int GCD(int m, int n)
{
    return !m ? n : GCD(n%m, m);
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
int a[maxn], n, t, m;


int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        string s1, s2;int n=str.size();
        for(int i=0;i<n;i+=2)
            s1.push_back(str[i]);
        for(int i=1;i<n;i+=2)
            s2.push_back(str[i]);
        reverse(s2.begin(), s2.end());
        cout<<s1<<endl<<s2<<endl;
    }
	return 0;
}
