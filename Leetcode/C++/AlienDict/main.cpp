#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

class Solution {
public:
  string alienOrder(vector<string>& words) {
    unordered_set<char> umch;
    int maxlen=0;
    for(auto se: words){
      maxlen=max(maxlen, (int)se.size());
      for(auto e: se){
        umch.insert(e);
      }
    }

    //mark in words and outof words char, as indegree 0 would be put in queue
    int indeg[26];
    memset(indeg, -1, sizeof indeg);
    for(auto e: umch){
      indeg[e-'a']=0;
    }

    int wordnum=words.size();
    unordered_set<int> edge[26];

    for(int i=0;i<maxlen;i++){
      for(int j=0;j<wordnum;j++){
        if(j-1>=0 && i<words[j].size() && i<words[j-1].size() && words[j][i] != words[j-1][i]
           && words[j-1].substr(0, i) == words[j].substr(0, i)){
          int fromindex=words[j-1][i]-'a', toindex=words[j][i]-'a';
          if( !edge[fromindex].count(toindex)){
            edge[fromindex].insert(toindex);
            indeg[toindex]++;
          }
        }
      }
    }
    queue<int> q;
    for(int i=0;i<26;i++){
      if(!indeg[i]) q.push(i);
    }
    string ans;
    while(!q.empty()){
      auto cur=q.front();q.pop();
      ans+=char('a'+cur);
      for(auto e: edge[cur]){
        if(!(--indeg[e])) q.push(e);
      }
    }
    return ans.size() == umch.size() ? ans: "";
  }
} S;


int main()
{
    vector<string> words={"ze","yf","xd","wd","vd","ua","tt","sz","rd", "qd","pz","op","nw","mt","ln","ko","jm","il", "ho","gk","fa","ed","dg","ct","bb","ba"};
    cout<<S.alienOrder(words)<<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
