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
private:
    char buffer[5];
    int bufi=0;
    int bufsize=0;
public:
    int read(char* buf, int n)
    {
        bool eof=0;
        int ttcnt=0;
        while(!eof && ttcnt< n)
        {
            if(bufsize>0)
            {
                int bytes=min(bufsize, n-ttcnt);
                memcpy(buf+ttcnt, buffer+bufi, bytes);
                ttcnt+=bytes;
                bufi+=bytes;
                bufsize-=bytes;
                if(bufsize>0) continue;
            }
            int curcnt=read4(buffer);
            if(curcnt<4) eof=1;
            int bytes=min(curcnt, n-ttcnt);
            memcpy(buf+ttcnt, buffer, bytes);
            bufi=bytes;
            bufsize=curcnt-bytes;
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
