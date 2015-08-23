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
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string, int> table;
        for(auto i: L) table[i]++;
        vector<int> ans;
        int ssize=S.size(), lsize=L.size();
        if(!ssize || !lsize) return ans;
        int subsize=L[0].size(); if(!subsize) return ans;
        for(int i=0;i+lsize*subsize<=ssize;i++)
        {
            unordered_map<string, int> tmpt=table;
            bool found=1;
            for(int k=0;k<=(lsize-1)*subsize;k+=subsize)
            {
                string cursub=S.substr(i+k, subsize);
                auto it=tmpt.find(cursub);
                if(it!=tmpt.end() && it->second>0)
                    it->second--;
                else
                {
                    found=0;
                    break;
                }
            }
            if(found) ans.push_back(i);
        }
        return ans;
    }
} F;

int main()
{
    string s="barfoothefoobarman";
    vector<string> l={"foo", "bar"};
    auto ans=F.findSubstring(s, l);
    for(auto i: ans) cout<<i<<" ";
    cout<<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
