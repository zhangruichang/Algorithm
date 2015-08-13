#include<bits\stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e+5 + 7;
pair<LL, int> arr[N];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i ^ n; ++i)
        scanf("%I64d", &arr[i].first), arr[i].second = i;
    sort(arr, arr + n);
    LL ans = 0;
    for (int i = 0; i ^ n; ++i)
    {
        if (arr[i].first % k)
            continue;
        ans += (LL)(upper_bound(arr, arr + n, make_pair(arr[i].first / k, arr[i].second - 1)) - lower_bound(arr, arr + n, make_pair(arr[i].first / k, 0))) *
            (upper_bound(arr, arr + n, make_pair(arr[i].first * k, n - 1)) - lower_bound(arr, arr + n, make_pair(arr[i].first * k, arr[i].second + 1)));
    }
    printf("%I64d\n", ans);
    return 0;
}
