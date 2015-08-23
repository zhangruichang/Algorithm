#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 100000;

int n, s, w[N], parent[N];
std::vector <int> queue;
std::vector <int> edges[N];
long long minimum[N];

long long solve(long long limit)
{
    memset(minimum, 0, sizeof(*minimum) * n);
    for (int i = n - 1; i >= 0; -- i) {
        int u = queue[i];
        minimum[u] += w[u];
        int p = parent[u];
        if (~p) {
            minimum[p] += std::min(minimum[u], limit);
        }
    }
    return minimum[s];
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++ t) {
        scanf("%d%d", &n, &s);
        s --;
        for (int i = 0; i < n; ++ i) {
            edges[i].clear();
        }
        for (int i = 0; i < n - 1; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        long long total = 0;
        for (int i = 0; i < n; ++ i) {
            scanf("%d", w + i);
            total += w[i];
        }
        memset(parent, -1, sizeof(*parent) * n);
        queue.clear();
        queue.push_back(s);
        for (int head = 0; head < (int)queue.size(); ++ head) {
            int u = queue[head];
            for (int v : edges[u]) {
                if (v != parent[u]) {
                    parent[v] = u;
                    queue.push_back(v);
                }
            }
        }
        long long low = 0;
        long long high = total;
        while (low < high) {
            long long middle = low + high >> 1;
            if (solve(middle) == total) {
                high = middle;
            } else {
                low = middle + 1;
            }
        }
        std::cout << "Case #" << t << ": " << high << std::endl;
    }
    return 0;
}
