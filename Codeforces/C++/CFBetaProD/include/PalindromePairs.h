#ifndef PALINDROMEPAIRS_H
#define PALINDROMEPAIRS_H
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

class PalindromePairs
{
    public:
        PalindromePairs();
        virtual ~PalindromePairs();
        vector<pair<string, string>> PalindromePairs1(vector<string> v)
        {
            unordered_map<string, int> hash;
            vector<pair<string, string>> ans;
            int n=v.size();
            for(int i=0;i<n;i++) hash[v[i]]=i;
            for(int i=0;i<n;i++)
            {
                int len=v[i].size();
                for(int j=1;j<=len;j++)
                {
                    string word1=v[i].substr(0, j), word2=v[i].substr(j, len-j);
                    if(isPa(word1))
                    {
                        string tmp=word2; reverse(tmp.begin(), tmp.end());
                        if(hash.find(tmp)!=hash.end() && hash[tmp]!=i)
                            ans.push_back({tmp, v[i]});
                    }
                    if(isPa(word2))
                    {
                        string tmp=word1; reverse(tmp.begin(), tmp.end());
                        if(hash.find(tmp)!=hash.end() && hash[tmp]!=i)
                            ans.push_back({v[i], tmp});
                    }
                }
            }
            return ans;
        }
    protected:
    private:
        bool isPa(string s)
        {
            int n=s.size();
            for(int i=0, j=n-1;i<j;i++, j--) if(s[i]!=s[j]) return 0;
            return 1;
        }
};

#endif // PALINDROMEPAIRS_H
