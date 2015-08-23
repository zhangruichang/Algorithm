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
const int maxn = 1e5 + 10;
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

int a[maxn], n, t, m, cnt;
unordered_map<string, int> um;


int Find(int x){
    if(a[x]==-1) return x;
    return a[x]=Find(a[x]);
}

void Union(int x, int y){
    int r1=Find(x), r2=Find(y);
    //cout<<"r1, r2: "<<r1<<" "<<r2<<endl;
    if(r1!=r2) a[r1]=r2;
}

int index(string s){
    if(um.count(s)) return um[s];
    um[s]=cnt;
    return cnt++;
}

bool Check(int x, int y){
    return Find(x)==Find(y);
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    cin>>n;cnt=1;
    fill_n(a, maxn, -1);
    um.clear();
    int q;string s1, s2;
    for(int i=0;i<n;i++){
        cin>>q>>s1>>s2;
        if(q==0){
            Union(index(s1), index(s2));
            //cout<<index(s1)<<" "<<index(s2)<<endl;
        }else{
            puts(Check(index(s1), index(s2))?"yes":"no");
        }
    }
	return 0;
}
