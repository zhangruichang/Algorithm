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
#include<sstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool v[10000];
vector<string> ans;
string cur, s;
int n;

void dfs(int now){
	if(now>=n){
		ans.push_back(cur);
		return ;
	}
	char last=-1;
	for(int i=0;i<n;i++){
		if(v[i] || s[i]==last) continue;
		cur+=s[i];
		v[i]=1;
		dfs(now+1);
		v[i]=0;
		cur.pop_back();
		last=s[i];
	}
}

vector<string> string_permutation(string s_){
	s=s_;
	n=s.size();
	sort(s.begin(), s.end());
	ans.clear(), cur.clear();
	fill_n(v, n, 0);
	dfs(0);
	return ans;
}



int main(){
	string s="bbaba";
	auto ans=string_permutation(s);
	for(auto e:ans) cout<<e<<endl;
	return 0;
}