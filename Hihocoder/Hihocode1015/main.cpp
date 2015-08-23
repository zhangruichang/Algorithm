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

int a[maxn], n, t, m, strn, patn;
string str, pat;
int Next[maxn];

void GetNext(){
    Next[0]=-1;
    for(int i=0;i<=patn-2;i++){
        int k=Next[i];
        while(k!=-1 && pat[k]!=pat[i])
            k=Next[k];
        Next[i+1]=k+1;
    }
}

int KMP(){
    GetNext();
    int i=0, j=0, ans=0;
    while(i<strn && j<patn-1){
        if(j==-1 || str[i]==pat[j]){
            i++, j++;
        }else{
            j=Next[j];
        }
        if(j==patn-1){
            j=Next[j];
            ans++;
        }
    }
    return ans;
}

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int n;
    int median(vector<int> &a) {
        n=a.size();
        return qselect(a, 0, n-1, (n+1)/2);
    }

    int qselect(vector<int> &a, int low, int high, int k){
        int mid=Partition(a, low, high);
        int order=mid-low+1;
        if(order==k) return a[mid];
        else if(order>k) return qselect(a, low, mid-1, k);
        else return qselect(a, mid+1, high, k-order);
    }

    int Partition(vector<int> &a, int low, int high){
        int i=low, j=high, pivot=a[low];
        while(i<j){
            while(i<j && a[j]>=pivot) j--;
            while(i<j && a[i]<=pivot) i++;
            if(i<j) swap(a[i], a[j]);
        }
        swap(a[low], a[i]);
        return i;
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
    vector<int> a={7, 9, 4, 5};
    cout<<S.median(a)<<endl;
	return 0;
}
