#ifndef REGULAR_H
#define REGULAR_H
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
using namespace std;

class Regular
{
    public:
        Regular();
        bool RegularExpressionMatch(const char* s, const char* p)
        {
            if(!*p) return !*s;
            if(*(p+1)!='*')//including *p='\0'
            {
                return (*p=='.'&& *s || *p==*s) && RegularExpressionMatch(s+1, p+1);
            }
            else
            {
                while(*s==*p || *p=='.' && *s)
                {
                    if(RegularExpressionMatch(s, p+2)) return 1;
                    s++;
                }
                return RegularExpressionMatch(s, p+2);
            }
        }
        bool ReExp_dp_three(const char* s, const char* p)
        {
            int plen=strlen(p), slen=strlen(s);
            bool dp[plen+1][slen+1];memset(dp, 0, sizeof dp);
            dp[0][0]=1;
            for(int i=1;i<=plen;i++)
            {
                if(p[i-1]!='*') dp[i][0]=0;
                else dp[i][0]=dp[i-2][0];
            }
            for(int j=1;j<=slen;j++) dp[0][j]=0;
            for(int i=1;i<=plen;i++)
            {
                if(p[i-1]!='*')
                {
                    for(int j=1;j<=slen;j++)
                        dp[i][j]=dp[i-1][j-1] && (p[i-1]=='.' && s[j-1] || p[i-1] == s[j-1]);
                }
                else
                {
                    for(int j=1;j<=slen;j++)
                    {
                        int k;
                        for(k=j;k>=1;k--)
                        {
                            if(s[k-1]==p[i-2] && dp[i-2][k])
                            {
                                dp[i][j]=1;
                                break;
                            }
                        }
                        if(k<=0) dp[i][j]=dp[i-2][k];
                    }
                }
            }
            //for(int i=0;i<=plen;i++) for(int j=0;j<=slen;j++)
            //    cout<<dp[i][j]<<" \n"[j==slen];
            return dp[plen][slen];
        }
        bool ReExp_Two(const char* s, const char* p)
        {
            int slen=strlen(s), plen=strlen(p);
            bool dp[plen+1][slen+1];
            memset(dp, 0, sizeof dp);
            dp[0][0]=1;
            for(int i=1;i<=plen;i++)
            {
                if(p[i]=='*')
                {
                    dp[i][0]=dp[i-1][0]=dp[i+1][0];
                    for(int j=1;j<=slen;j++)
                    {
                        dp[i][j]=dp[i+1][j]=(dp[i][j-1] && (p[i-1] ==s[j-1] || p[i-1]=='.' && s[j-1]) || dp[i-1][j]);
                    }
                    i++;
                }
                else
                {
                    for(int j=1;j<=slen;j++)
                        dp[i][j]=dp[i-1][j-1] && (p[i-1] == s[j-1] || p[i-1]=='.' && s[j-1]);
                }
            }
            return dp[plen][slen];
        }
        virtual ~Regular();
        Regular(const Regular& other);
        Regular& operator=(const Regular& other);
    protected:
    private:
};

#endif // REGULAR_H
