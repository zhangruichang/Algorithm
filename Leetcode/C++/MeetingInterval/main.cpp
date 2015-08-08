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

struct Interval{
    int start ,end;
};

struct Node{
    int x;
    Node(int x_): x(x_){}
    bool operator<(const Node& n) const{
        return x>n.x;
    }
};

class Solution{
public:
    static bool comp(Interval p1, Interval p2){
        if(p1.start!=p2.start) return p1.start<p2.start;
        return p1.end<p2.end;
    }
    bool MeetingIntervalI(vector<Interval> v){//[1,3], [2,4]
        int n=v.size();if(!n) return 1;
        sort(v.begin(), v.end(), comp);
        for(int i=1;i<n;i++){
            if(v[i].start<v[i-1].end) return 0;
        }
        return 1;
    }
//Marzullo's algorithm
    int MeetingIntervalII(vector<Interval> v){//[1,3] [3,5] return 1
        int n=v.size();if(!n) return 0;
        vector<pair<int, bool>> t;//1 start, 0 end
        for(auto e: v){
            t.push_back({e.start, 1});
            t.push_back({e.end, 0});
        }
        sort(t.begin(), t.end());
        int maxdep=0, curdep=0;
        for(auto e: t){
            if(e.se) curdep++;
            else curdep--;
            maxdep=max(maxdep, curdep);
        }
        return maxdep;
    }
    int MeetingIntervalII_Heap(vector<Interval> v){
        priority_queue<Node> pq;
        sort(v.begin(), v.end(), comp);
        int maxdep=0;
        for(auto e : v){
            while(!pq.empty() && pq.top().x <= e.start) pq.pop();
            pq.push({e.end});
            maxdep=max(maxdep, (int)pq.size());
        }
        return maxdep;
    }
} S;

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    vector<Interval> v={{1,4}, {2,6}, {5,7}, {3,10}};
    cout<<S.MeetingIntervalI(v)<<endl;
    cout<<S.MeetingIntervalII(v)<<endl;
    cout<<S.MeetingIntervalII_Heap(v)<<endl;
	return 0;
}
