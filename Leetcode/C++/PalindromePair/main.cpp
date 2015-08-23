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

bool isPa(string word) {
    int len = word.size();
    for(int i = 0; i < len/2; i ++) {
        if(word[i] != word[len-1-i]) {
            return false;
        }
    }
    return true;
}

vector<pair<string, string> > PalindromePair(vector<string> dict)
{
    vector<pair<string, string> > ans;
    unordered_set<string> hash;
    int n=dict.size();

    for(auto i: dict) hash.insert(i);
    for(int i=0;i<n;i++)
    {
        int L=dict[i].size();
        for(int l=0;l<=L;l++)
        {
            string sub1=dict[i].substr(0, l);
            string sub2=dict[i].substr(l, L-l);
            if(isPa(sub1))
            {
                string tmp=sub2;
                reverse(tmp.begin(), tmp.end());
                if(hash.find(tmp)!=hash.end() && tmp!=dict[i])
                    ans.push_back({tmp, dict[i]});
            }
            if(isPa(sub2))
            {
                string tmp=sub1;
                reverse(tmp.begin(), tmp.end());
                if(hash.find(tmp)!=hash.end() &&tmp!=dict[i])
                    ans.push_back({dict[i],tmp});
            }
        }
    }
    return ans;
}

double func(double x)
{//(start, end)

}

double invert(double y, double start, double end)
{
    double low=start, high=end;
    while(abs(low-high)>1e-12)
    {
        int mid=(low+high)/2;
        double ans=func(mid);
        if(abs(ans-y)<1e-12) return mid;
        else if(ans>y) high=mid;
        else low=mid;
    }
}

typedef long long LL;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(!dividend || !divisor) return 0;
        bool positive=1;
        if(dividend>0 && divisor<0 || dividend<0 && divisor>0) positive=0;
        LL de=abs((LL)dividend), ds=abs((LL)divisor);
        LL sum=0;
        while(1)
        {
            LL ans=1;
            LL tmp=ds;
            while(tmp<=de) tmp<<=1, ans<<=1;
            cout<<ans<<" ";
            ans>>=1, tmp>>=1;;
            if(!ans) break;
            sum+=ans;
            de-=tmp;
        }
        return positive ? sum: -sum;
    }
} F;

int main() {
    cout<<endl<<F.divide(10,3)<<endl;
    /*
    vector<string> words;
    words.push_back("abc");
    words.push_back("ba");
    words.push_back("aaa");
    words.push_back("a");
    words.push_back("cb");
    words.push_back("cba");
    words.push_back("ccab");

    vector<pair<string, string> > rst = PalindromePair(words);

    for(int i = 0; i < rst.size(); i ++) {
        cout << rst[i].first << " " << rst[i].second << endl;
    }*/
    return 0;
}
