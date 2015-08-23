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
    int a ,ans;
    while(cin>>a)
    {
        if(a>=0)
        {
            int tmp=a;
            int ge=tmp%10;tmp/=10;
            int shi=tmp%10;
            if(shi==8) ans= ge==9 ? 9 : 1;
            else if(shi==7) ans= (ge<=7) ? (8-ge) : (10-ge);
            else ans= (ge<=7) ? (8-ge) : (18-ge);
        }
        else if(a<-8)
        {
            int tmp=-a;
            int ge=tmp%10;tmp/=10;
            int shi=tmp%10;
            if(shi==8) ans= (ge==0) ? 2 : 1;
            else if(shi==9) ans= (ge==9) ? 1 : ge+1;
            else ans= (ge==9) ? 1 : (ge+2);
        }
        else
        {
            ans=8-a;
        }
        cout<<ans<<endl;
    }
	return 0;
}
