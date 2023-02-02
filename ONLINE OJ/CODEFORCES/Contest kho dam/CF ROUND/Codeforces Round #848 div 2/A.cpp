#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(t1) t1.begin(), t1.end()
using namespace std;


const int maxN = 1e5 + 10;

int n, m, d;
int a[maxN];
int b[maxN];
map<int, int> ccount;

int check(int ans, int i){
    // for (int i = 1; i <= n; i++){
    //     cout << "CHECK" << b[i] << " " << a[i] << endl;
    // }

    int del = ccount[b[i + 1]] - ccount[b[i]];
    if (d + 2 <= n)
    {
        return min(ans, d + 1 - del);
    }
    return ans;
}

signed main()
{
    int test;
    cin >> test;
    while (test--)
    {
        
        cin >> n >> m >> d;
        ccount.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
        }

        for (int i = 1; i <= n; i++)
        {
            ccount[a[i]] = i + 1;
        }

        int ans = 1e18;
        for (int i = 1; i <= m - 1; i++)
        {
            if (ccount[b[i + 1]] > ccount[b[i]] + d or ccount[b[1 + i]] <= ccount[b[i]])
            {
                if (n > m * n){
                    cout << "OK" << endl;
                }
                cout << 0 << endl;
                goto lmao;
            }
            ans = min(ans, ccount[b[i + 1]] - ccount[b[i]]);
            for (int i = 1; i <= n and n == 0; i++){
                cerr << "CHECK" << b[i] << " " << a[i] << endl;
            }
            ans = check(ans,i);
            
        }
        cout << ans << endl;
        lmao:;
    }
}