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
LL a[maxn], n, t, m;


bool comp1(pair<LL, LL> p1, pair<LL, LL> p2){
    return p1.fi<p2.fi;
}

bool comp2(pair<LL, LL> p1, pair<LL, LL> p2){
    if(p1.fi!=p2.fi) return p1.fi<p2.fi;
    return p1.se<p2.se;
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    LL n,k;
    cin>>n>>k;
    vector<pair<LL, LL>> v;
    for(LL i=0;i<n;i++) cin>>a[i], v.push_back({a[i], i});
    sort(v.begin() ,v.end());
    LL ans=0;
    for(LL i=0;i<n;i++){
        if(a[i]%k) continue;
        LL low=0, high=i-1;
        while(low<high){
            LL mid=(low+high)/2;
            if(v[mid].fi < a[i]/k) low=mid+1;
            else high=mid;
        }
        LL it1s;
        if(v[low].fi== a[i]/k && v[low].se < i) it1s=low;
        else continue;
        low=0, high=i-1;
        while(low<high){
            LL mid=(low+high)/2;
            if(v[mid].fi==a[i]/k || v[mid].fi < a[i]/k && v[mid].se<i) low=mid+1;
            else high=mid;
        }
        LL it1e=low;
        if(v[low].fi>a[i]/k || v[low].fi==a[i]/k && v[low].se<i) it1e++;
        low=i+1, high=n-1;
        while(low<high){
            LL mid=(low+high)/2;
            if(v[mid].fi<a[i]*k || v[mid].fi == a[i]*k && v[mid].se < i) low=mid+1;
            else high=mid;
        }
        LL it2s=low;
        if(! (v[low].fi == a[i] * k && v[low].se > i)) continue;
        low=i+1, high=n-1;
        while(low<high){
            LL mid=(low+high)/2;
            if(v[mid].fi <= a[i]*k) low=mid+1;
            else high=mid;
        }
        LL it2e=low;
        if(v[low].fi<=a[i]*k) continue;
        cout<<i<<" "<<it1s<<" "<<it1e<<" "<<it2s<<" "<<it2e<<endl;
        /*
        auto it1s=lower_bound(v.begin(), v.begin()+i, make_pair(a[i]/k, i), comp1),
        it1e=upper_bound(v.begin(), v.begin()+i, make_pair(a[i]/k, i), comp2),
        it2s=lower_bound(v.begin()+i+1, v.end(), make_pair(a[i]*k, i), comp2),
        it2e=upper_bound(v.begin()+i+1, v.end(), make_pair(a[i]*k, i), comp2);
        */
        ans+=(LL)(it1e-it1s+1) * (it2e-it2s+1);
    }
    cout<<ans<<endl;
	return 0;
}
