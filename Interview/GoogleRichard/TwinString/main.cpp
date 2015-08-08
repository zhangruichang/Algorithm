#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define fi first
#define se second

string getNext( string s ) //start from a
{
	int len = s.length();
	vector<int> pi( len, 0 );
	// pi[a]=0;
	int k = 0;
	string res = "";
	for ( int i = 1; i < len; ++i ) {
		k = pi[i - 1];
		while ( k > 0 && s[k] != s[i] ) k = pi[k - 1];
		k += ( s[k] == s[i] );
		pi[i] = k;
		if (k!=0 && i & 1 ) {
			int a = i + 1 - k;
			int b = k / a;
			if ( b&1 && a * ( b + 1 ) == i + 1 ) {
				res = s.substr( 0, i + 1 );
			}
		}
	}
	return res;
}

string findTwins( string s )
{
	//cout << s << ":" << endl;
	int len = s.length();
	string ans;
	for ( int i = 0; i < len; ++i ) {
		string ss = getNext( s.substr( i, len - i ) );
		if(ans.size()<ss.size()){
            ans=ss;
		}
		//if ( ss != "" )
		//	cout << i << "," << ss << endl;
	}
	return ans;
	//cout << endl;
}

string MyLongestTwinSubStr(string s){
    unordered_map<string, unordered_set<int>> um;
    int n=s.size();
    string ans;
    for(int i=0;i<n;i++) for(int j=i;j<n;j++){
        string cur=s.substr(i, j-i+1);
        auto it=um.find(cur);
        if( it!=um.end() &&
           ( it->se.count(i+cur.size()) || it->se.count(i-cur.size())
            )){
            if(ans.size()<2*cur.size()){
                ans=cur+cur;
            }
        }
        um[cur].insert(i);
    }
    return ans;
}

int main()
{
    for(int i=0;i<100;i++){
        int len=rand()%100;
        string s(len, 'a');
        for(int i=0;i<len;i++){
            s[i]=rand()%26+'a';
        }
        string ans1=MyLongestTwinSubStr(s), ans2=findTwins(s);
        if(ans1!=ans2){
            cout<<s<<": "<<ans1.size()<<" "<<ans1<<" "<<ans2.size()<<" "<<ans2<<endl;
        }
    }
	//cout<<findTwins( "aaa" )<<endl;
	//cout<<findTwins( "bilibilibli" )<<endl;
	//cout<<findTwins( "bilibilibilibili" )<<endl;
	//cout<<findTwins( "aaaa" )<<endl;
	//cout<<findTwins( "abcabcabcabc" )<<endl;
}
