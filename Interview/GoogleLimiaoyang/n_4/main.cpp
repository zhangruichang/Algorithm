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

int a[maxn], n, t, m;

int Lower_bound(vector<int> a, int low, int high, int val, int n);

//sorted array whether it has >=n/4 element
bool Hasn_4(vector<int> v){
    int n=v.size();
    if(n<4) return 1;
    int n1=Lower_bound(v, 0, n/4, v[n/4], n);
    //int n1=lower_bound(v.begin(), v.begin()+n/4, v[n/4])-v.begin();
    if(n1==-1 || v[n1+n/4-1]==v[n/4]) return 1;

    int n2=Lower_bound(v, n/4+1, n/2, v[n/2], n);

    //int n2=lower_bound(v.begin()+n/4+1, v.begin()+n/2, v[n/2])-v.begin();

    if(n2==n/4 || v[n2+n/4-1]==v[n/2]) return 1;

    int n3=Lower_bound(v, n/2+1, 3*n/4, v[3*n/4], n);
    //int n3=lower_bound(v.begin()+n/2+1, v.begin()+3*n/4, v[3*n/4])-v.begin();
    if(n3==n/2 || v[n3+n/4-1]==v[3*n/4]) return 1;
    return 0;
}

//find first index in [low, high], that a[index]==val, if not found, return high+1;
int Lower_bound(vector<int> a, int low, int high, int val, int n){
    while(low<high){
        int mid=(low+high)/2;
        if(a[mid] == val){
            if(mid+n/4-1< n && a[mid] == a[mid+n/4-1])
                return low-1;
            else high=mid;
        }
        else if(a[mid] < val) low=mid+1;
        else high=mid-1;
    }
    if(low == high && a[low] == val) return low;
    return high+1;//if not in [low, high], return high+1
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    vector<int> v={1,2,2,3,3,4,4,5,6,6,6,7};
    cout<<Hasn_4(v)<<endl;
	return 0;
}
