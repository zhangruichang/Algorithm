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

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<int> rowone={1};
        vector<vector<int> >ans; if(!numRows) return ans;
        ans.push_back(rowone);
        for(int i=2;i<=numRows;i++)
        {
            vector<int> cur(i, 0);
            for(int j=0;j<i;j++)
            {
                cur[j]= (j<=i-2 ? ans[i-2][j] : 0) + (j>=1 ? ans[i-2][j-1] : 0);
                if(j==1)
                    cout<<ans[i-2][j]<<" "<<ans[i-2][j-1]<<" "<<cur[j]<<endl;
            }
            ans.push_back(cur);
        }
        return ans;
    }
} F;

int main()
{
    auto ans=F.generate(3);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
