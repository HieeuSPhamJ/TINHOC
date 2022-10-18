#include <bits/stdc++.h>

#define nxt "\n"

using namespace std;
const int N = 2e5 + 5;

char state[N];
long long ans;
long long a[N];
int n, curr;

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Test;
    cin >> Test;
    for (int TestCase = 1; TestCase <= Test; ++ TestCase)
    {
        cin >> n;
        state[n + 1] = state[n + 2] = '0';
        a[n + 1] = a[n + 2] = 0;
        ans = 0;
        for (int i = 1; i <= n; ++ i)
        {
            cin >> state[i];
        }
        for (int i = 1; i <= n; ++ i)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++ i)
        {
            if (state[i] == '1')
            {
                ans = ans + a[i];
            }
            else
            {
                curr = i + 1;
                while (curr <= n && state[curr] == '1')
                {
                    if (a[i] >= a[curr])
                    {
                        ans = ans + a[i];
                        state[i] = '1';
                        state[curr] = '0';
                        break;
                    }
                    ++ curr;
                }
            }
        }
        cout << ans << nxt;
    }
    return 0;
}