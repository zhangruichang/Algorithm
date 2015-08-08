#ifndef LCS_H
#define LCS_H
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
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
#include "LCS.h"
using namespace std;
const int maxn = 1e5 + 10;
class LCS
{
    public:
        LCS();
        virtual ~LCS();
        vector<vector<int>> LCS_Solution(vector<int>& v)
        {
            v_=v;
            int n=v.size();
            dp[0]=0;
            for(int i=1;i<=n;i++)
            {
                dp[i]=1;
                for(int j=1;j<i;j++)
                    if(v[i-1]>v[j-1])
                        dp[i]=max(dp[i], dp[j]+1);
            }
            ans.clear(), cur.clear();
            dfs(n);
            return ans;
        }
        void dfs(int i)
        {
            if(!i)
            {
                ans.push_back(cur);
                reverse(ans.back().begin(), ans.back().end());
                return ;
            }
            for(int j=0;j<i;j++)
            {
                if(dp[i]==dp[j]+1 && (!j || v_[i-1]>v_[j-1]))
                {
                    cur.push_back(v_[i-1]);
                    dfs(j);
                    cur.pop_back();
                }
            }
        }
    protected:
    private:
        vector<vector<int>> ans;
        vector<int> cur, v_;
        int dp[maxn];
};

#endif // LCS_H
