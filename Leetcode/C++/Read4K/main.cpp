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

int read4(char* buf) ;

class Solution
{
public:
    int read(char* buf, int n)
    {
        char buffer[5];
        bool eof=0;
        int ttcnt=0;
        while(!eof && ttcnt<n)
        {
            int curcnt=read4(buffer);
            if(curcnt<4) eof=1;
            int bytes=min(n-ttcnt, curcnt);
            memcpy(buf+ttcnt, buffer, bytes);
            ttcnt+=bytes;
        }
        return ttcnt;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
