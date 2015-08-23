#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
int SingleNum(int a[], int n)//1 1 2 2 3 5 5
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(!mid) return a[0];
        if(mid==n-1) return a[n-1];
        if(a[mid] !=a[mid-1] && a[mid] != a[mid+1]) return a[mid];
        else if(a[mid]!=a[mid-1])
        {
            if(mid & 1) high=mid-1;
            else low=mid+1;
        }
        else if(a[mid]!=a[mid+1])
        {
            if(mid & 1) low=mid+1;
            else high=mid-1;
        }
    }
}
int main()
{
    int a[]={3};int n=sizeof(a)/sizeof(int);
    cout<<SingleNum(a,n)<<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
