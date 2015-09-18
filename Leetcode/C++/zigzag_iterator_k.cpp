//v[0]={1,2}
//v[1]={3,4,5,6}
//v[2]={7,8}
//output: {1,3,2,4,5,6}
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
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
class ZigzagIterator_k{
public:

	vector<vector<int>> v;
	vector<int> index;
	int vi, vnum;
	int ttnum;
	ZigzagIterator_k(vector<vector<int>> v_){
		v=v_;
		index.assign(v.size(), 0);
		vi=0;
		vnum=0;
		ttnum=0;
		for(auto e: v){
			ttnum+=e.size();
		}
	}
	
	int next(){
		for(;index[vi]>=v[vi].size();vi=(vi+1)%v.size());
		int ans=v[vi][index[vi]];
		index[vi]++;
		vi=(vi+1)%v.size(),vnum++;
		return ans;
	}
	
	bool hasNext(){
		return vnum<ttnum;
	}
};


/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
	vector<vector<int>>v({{},{},{7,8}});
	ZigzagIterator_k S(v);;
	while(S.hasNext()){
		cout<<S.next()<<" ";
	}
	puts("");
	return 0;
}