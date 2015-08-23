#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include <algorithm>
using namespace std;

bool isPal(string word) {
    int len = word.size();
    for(int i = 0; i < len/2; i ++) {
        if(word[i] != word[len-1-i]) {
            return false;
        }
    }
    return true;
}

vector<pair<string, string> > palindomPair(vector<string> &words) {
    vector<pair<string, string> > rst;
    unordered_set<string> dict;
    for(int i = 0; i < words.size(); i ++) {
        dict.insert(words[i]);
    }
    for(int i = 0; i < words.size(); i ++) {
        int len = words[i].size();
        for(int l = 0; l <= len; l ++) {
            string sub1 = words[i].substr(0, l);
            string sub2 = words[i].substr(l, len-l);
            if(isPal(sub2)){
                string tmp = sub1;
                reverse(tmp.begin(), tmp.end());
                if(dict.find(tmp) != dict.end() && words[i] != tmp) {
                    rst.push_back(pair<string, string>(words[i], tmp));
                }
            }
            if(isPal(sub1)){
                string tmp = sub2;
                reverse(tmp.begin(), tmp.end());
                if(dict.find(tmp) != dict.end() && words[i] != tmp) {
                    rst.push_back(pair<string,string>(tmp, words[i]));
                }
            }
        }
    }
    return rst;
}


int main() {
    vector<string> words;
    words.push_back("abc");
    words.push_back("ba");
    words.push_back("aaa");
    words.push_back("a");
    words.push_back("cb");
    words.push_back("cba");
    words.push_back("ccab");

    vector<pair<string, string> > rst = palindomPair(words);

    for(int i = 0; i < rst.size(); i ++) {
        cout << rst[i].first << " " << rst[i].second << endl;
    }
    return 0;
}
