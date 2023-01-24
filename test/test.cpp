#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int N = 1e5 + 5;
int n , m , q;

ii a[N][12];
int b[N][12];

signed main()
{
    //freopen("D.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n >> m;
        set < int > s;
        for (int i = 1; i <= n; i++)
        {
            for (int j= 1; j <= m; j++)
            {
                cin >> b[i][j];
                a[i][j].fi = b[i][j];
                a[i][j].se = j;
            }
            sort(a[i] + 1 , a[i] + 1 + m);
            int x = 0;
            for (int j= 1; j <= m; j++)
            {
                x = x * 10 + a[i][j].se;
                s.insert(x);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int x = 0;
            for (int j= 1; j <= m + 1; j++)
            {
                if(j == m + 1)
                {
                    cout << j - 1 << " ";
                    break;
                }
                x = x * 10 + b[i][j];
                if(s.find(x) == s.end())
                {
                    cout << j - 1 << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
}