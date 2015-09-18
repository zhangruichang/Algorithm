//v1={1,2}
//v2={3,4,5,6}
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
class ZigzagIterator{
public:
	bool current;//0 means last visit v2, 1 means v1
	int index1, index2;
	vector<int> v1, v2;
	ZigzagIterator(vector<int>& v1_, vector<int> & v2_){
		v1=v1_, v2=v2_;
		current=0;
		index1=index2=0;
	}
	
	int next(){
		if(!hasNext()) return INT_MIN;
		if(!current){
			if(index1<v1.size()) {current=!current; return v1[index1++];}
			else if(index2<v2.size()) return v2[index2++];
		}else{
			if(index2<v2.size()) {current=!current; return v2[index2++];}
			else if(index1<v1.size()) return v1[index1++];
		}
	}
	
	bool hasNext(){
		if(!current){
			if(index1<v1.size()) return 1;
			else if(index2<v2.size()) return 1;
			else return 0;
		}else{
			if(index2<v2.size()) return 1;
			else if(index1<v1.size()) return 1;
			else return 0;
		}
	}
};


/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
	vector<int> v2={1,2}, v1={3,4,5,6,7};
	zigzag_iterator S(v1, v2);;
	while(S.hasnext()){
		cout<<S.next()<<" ";
	}
	puts("");
	return 0;
}