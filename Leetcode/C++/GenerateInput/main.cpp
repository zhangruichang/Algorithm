/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <bits/stdc++.h>>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)

int main()
{

#ifndef ONLINE_JUDGE
    //freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif

    //vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    //cout<<S.HousePaint(v)<<endl;
    srand (time(NULL));
    //unordered_set<int> us;
    for(int i=0;i<=100;){
        int len=i;
        cout<<"[";
        int k=rand()%20+1;
        for(int i=0;i<len;i++){
            if(i) cout<<",";
            cout<<"[";
            for(int j=0;j<k;j++){
                if(!j){
                    cout<<rand()%20+1;
                }else{
                    cout<<","<<rand()%20+1;
                }
            }
            cout<<"]";
        }
        cout<<"]"<<endl;;
        i++;
    }
	return 0;
}
