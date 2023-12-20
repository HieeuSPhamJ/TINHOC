#include "bits/stdc++.h"
#define int long long
// #define double long double
#define ii pair<int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int n;
int p[4][maxN];
int pos[3][maxN];
int res[3];
int in[maxN];
int fr[1 << 3];
int wh[maxN];
int resp[maxN];
int temp[maxN];
namespace sub12
{

    int get1(int a, int b)
    {
        pair<ii, int> best = {{1e9, 1e9}, 1e9};

        for (int t = 0; t < 3; t++)
        {
            pair<ii, int> tmp = {{min(pos[t][a], pos[t][b]), max(pos[t][a], pos[t][b])}, t};
            best = min(best, tmp);
        }
        return best.se;
    }

    int get2(int a, int b)
    {
        pair<ii, int> best = {{1e9, 1e9}, 1e9};

        for (int t = 0; t < 3; t++)
        {
            pair<ii, int> tmp = {{min(pos[t][a], pos[t][b]), max(pos[t][a], pos[t][b])}, t};
            best = min(best, tmp);
        }
        return p[best.se][best.fi.fi];
    }


    void solve()
    {

        for (int i = 1; i <= n; i++)
        {
            vector<int> ls;
            for (int t = 0; t <= 2; t++)
            {
                if (wh[p[t][i]] == 0 || wh[p[t][i]] == i)
                {
                    if (wh[p[t][i]] == 0)
                    {
                        ls.push_back(p[t][i]);
                        wh[p[t][i]] = i;
                    }
                    in[p[t][i]] |= 1 << t;
                }
            }
            for (auto it : ls)
            {
                for (int conf = 1; conf < (1 << 3); conf++)
                {
                    ii best = {1e9, 1e9};
                    for (int t = 0; t < 3; t++)
                    {
                        if ((conf >> t) & 1)
                        {
                            ii tmp = {pos[t][it], t};
                            best = min(best, tmp);
                        }
                    }
                    res[best.se] += fr[conf];
                }
            }
            for (auto it : ls)
            {
                fr[in[it]]++;
            }
            for (int i = 0; i < (int)ls.size(); i++)
            {
                for (int j = i + 1; j < (int)ls.size(); j++)
                {
                    res[get1(ls[i], ls[j])]++;
                    resp[get2(ls[i], ls[j])]++;
                }
            }
            temp[i - 1] += (int)ls.size();
        }

        for (int i = n; i >= 0; i--)
        {
            temp[i] += temp[i + 1];
        }

        for (int i = 1; i <= n; i++)
        {
            resp[i] += temp[wh[i]];
        }

        for (int i = 0; i < 3; i++)
            cout << res[i] << " ";
        cout << endl;
        for (int i = 1; i <= n; i++)
            cout << resp[i] << " ";
        cout << endl;

        return;
    }

}

signed main()
{
    // freopen("input.INP", "r", stdin);
    // freopen("output.OUT", "w", stdout);
    if (fopen("qq.inp", "r"))
    {
        freopen("qq.inp", "r", stdin);
        freopen("qq.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int t = 0; t <= 2; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> p[t][i];
            pos[t][p[t][i]] = i;
        }
    }

    if (n <= 3000)
    {
        sub12::solve();
    }

    return 0;
}