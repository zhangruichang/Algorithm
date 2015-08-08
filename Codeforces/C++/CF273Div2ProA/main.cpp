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
#include<iostream>
#include<algorithm>
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


int main()
{
    int c1,c2,c3,c4,c5;
    while(cin>>c1)
    {
        cin>>c2>>c3>>c4>>c5;
        int sum=c1+c2+c3+c4+c5;
        if(sum%5==0 && sum>0)
            cout<<sum/5;
        else
            cout<<"-1";
        cout<<endl;

    }
	return 0;
}
