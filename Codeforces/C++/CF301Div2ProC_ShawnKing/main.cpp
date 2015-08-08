#include <iostream>
#include <vector>
#include <string>
#include "stdio.h"
using namespace std;

int n, m, r1, c1, r2, c2;
char mx[505][505];
bool ok;

bool board(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int rd1, int cd1, int rd2, int cd2)
{
    if (ok || (mx[rd1][cd1] == 'X' && (rd1 != rd2 || cd1 != cd2))) return;
    if (rd1 == rd2 && cd1 == cd2 && mx[rd1][cd1] == 'X')
    {
        ok = true;
        return;
    }
    mx[rd1][cd1] = 'X';
    char temp;
    if (board(rd1 - 1, cd1))
    {
        temp = mx[rd1 - 1][cd1];
        dfs(rd1 - 1, cd1, rd2, cd2);
        mx[rd1 - 1][cd1] = temp;
    }
    if (board(rd1 + 1, cd1))
    {
        temp = mx[rd1 + 1][cd1];
        dfs(rd1 + 1, cd1, rd2, cd2);
        mx[rd1 + 1][cd1] = temp;
    }
    if (board(rd1, cd1 - 1))
    {
        temp = mx[rd1][cd1 - 1];
        dfs(rd1, cd1 - 1, rd2, cd2);
        mx[rd1][cd1 - 1] = temp;
    }
    if (board(rd1, cd1 + 1))
    {
        temp = mx[rd1][cd1 + 1];
        dfs(rd1, cd1 + 1, rd2, cd2);
        mx[rd1][cd1 + 1] = temp;
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mx[i][j];
    cin >> r1 >> c1 >> r2 >> c2;
    ok = false;
    mx[r1 - 1][c1 - 1] = '.';
    dfs(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
