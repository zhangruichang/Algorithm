#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long LL;
int t, n;
int a[100000];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin>>t;
    while(t--)
    {
        cin>>n;
        unordered_map<int, int> us;
        for(int i=0;i<n;i++) cin>>a[i], us[a[i]]++;
        LL ans=0;
        for(auto e: us)
        {
            ans+=(LL)e.second*(e.second-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
