#include <iostream>

using namespace std;

const int mx = 100010;


int main() {
    int dp[mx];
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == s[i]) {
            dp[i] = dp[i - 1] + 1;
        }
        else {
            dp[i] = dp[i - 1];
        }
    }

    int n;
    cin >> n;

    int l, r;
    while(n--)
    {
        cin >> l >> r;
        cout << dp[r - 1] - dp[l - 1] << endl;
    }

    return 0;
}
