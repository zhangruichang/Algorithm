#include <iostream>

using namespace std;


class Solution{
public:
    char FirstNonrepeatChar(string s){
        for(int i=0;i<s.size();i++){
            auto e=s[i];
            if(!um.count(e)){
                um[e].fi=i,um[e].se++;
            }else{
                um[e].se++;
            }
        }
        int pos=-1;
        for(auto e: um){
            if(e.se==1) pos=min(pos, e.fi);
        }
        return pos!=-1 ? s[pos] : 0;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
