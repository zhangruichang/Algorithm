#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first

class Solution{
public:
    int firstUniqueChar(string s){
        unordered_map<char, pair<int, int>> um;
        for(int i=0;i<s.size();i++){
            auto e=s[i];
            if(!um.count(e)){
                um[e].fi=i,um[e].se++;
            }else{
                um[e].se++;
            }
        }
        int pos=s.size();
        for(auto e: um){
            if(e.se.se==1) pos=min(pos, e.se.fi);
        }
        return pos!=s.size() ? s[pos] : 0;
    }
} S;

int main()
{
    freopen("../../GenerateData/FindFirstNonRepeatedChar.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    string s;//="opvybjzoxhzubdntoamzottcjtuegmpqkcdbbgckjqtebichznpprqiswbdhoyncsaetlgbfviocfwxwdrnlffbfhvyxzukjwocy";
    while(cin>>s){
      string s1=s.substr(1, s.size()-2);
      cout<<S.firstUniqueChar(s1)<<endl;
    }
    return 0;
}
