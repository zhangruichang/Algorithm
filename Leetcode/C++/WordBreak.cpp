#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <string>
#include <cstdlib>
#include <unordered_set>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict){
		int n = s.size();
		bool dp[n+1];
		memset(dp, 0 ,sizeof dp);
		dp[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				dp[i] = dp[i] || dp[j] && dict.count(s.substr(j, i-j));
			}
		}
		return dp[n];
	}
};


int main()
{
	Solution S;
	string s="leetcode";
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	cout<<S.wordBreak(s,dict)<<endl;
	return 0;
}

