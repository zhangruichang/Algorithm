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

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    struct Node1{
        int x;
        bool operator<(const Node1& n) const{
            return x<n.x;
        }
    };
    struct Node2{
        int x;
        bool operator<(const Node2& n) const{
            return x>n.x;
        }
    };
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        priority_queue<Node1> pq1;
        priority_queue<Node2> pq2;
        vector<int> ans;
        int median=INT_MIN;
        for(auto e: nums){
            if(median==INT_MIN){
                median=e;
            }else if(e>median){
                if(pq1.size()==pq2.size()){
                    pq2.push({e});
                }else{
                    pq1.push({median});
                    median=pq2.top().x;
                    pq2.pop();
                    pq2.push({e});
                }
            }else{
                if(pq1.size()==pq2.size()){
                    pq2.push({median});
                    median=pq1.top().x;
                    pq1.pop();
                    pq2.push({e});
                }else{
                    pq1.push({e});
                }
            }
            ans.push_back(median);
        }
        return ans;
    }
};



int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/

	return 0;
}
