# include <bits\stdc++.h>

using namespace std;



bool check(int x)
{
     if (x < 0) x = -x;
     while (x)
     {
           if (x % 10 == 8) return 1;
           x /= 10;
     }
     return 0;
}
int main()
{
    int n;
    while(cin >> n)
    {
        for (int i = 1; i <= 10; i++)
        {
            if (check(n + i))
            {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
