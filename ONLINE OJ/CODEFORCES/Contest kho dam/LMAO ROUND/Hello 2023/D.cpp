#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int n, m;
int a[maxN];
int b[maxN];
int temp[maxN];
vector<int> lists[maxN];
vector<int> tempLists[maxN];
set<int> cant;
vector<int> adu;
bool ok;

void init(){
    cant.clear();
    adu.clear();
    for (int i = 1; i < maxN; i++)
    {
        lists[i].clear();
        tempLists[i].clear();
    }
}

bool check()
{
    int ok = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] < b[i])
            ok = 1;
    return ok;
}

signed main()
{
    
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        init();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        cin >> m;
        for (int i = 1; i <= m; i++)
            cin >> temp[i];
        sort(temp + 1, temp + m + 1);

        if (check())
        {
            cout << "NO" << endl;
            continue;
        }

        int ok = 0;
        for (int i = 1; i <= n; i++)
        {
            int t = lower_bound(temp + 1, temp + m + 1, b[i]) - temp;
            t--;
            if (t > 0)
                tempLists[t].push_back(i);
            if (a[i] != b[i])
            {
                t = upper_bound(temp + 1, temp + m + 1, b[i]) - temp;
                t--;
                if (t <= 0 || temp[t] != b[i])
                {
                    ok = 1;
                    break;
                }
                // cout<<t<<' ';
                lists[t].push_back(i);
            }
        }
        if (ok)
        {
            cout << "NO" << endl;
            for (int i = 1; i <= m; i++)
            {
                lists[i].clear();
                tempLists[i].clear();
            }
            continue;
        }
        ok = 0;
        int l = 0;
        for (int i = m; i >= 1; i--)
        {
            if (lists[i].size() > 0)
            {
                for (int v : lists[i])
                {
                    adu.push_back(v);
                }
            }
            for (int v : tempLists[i])
                cant.insert(v);
            // for(int v: adu) cout<<v<<'\n';
            // cout<<'\n';
            if (adu.size() and l < adu.size())
            {
                int r;
                auto f = cant.lower_bound(adu[l]);
                for (r = l + 1; r < adu.size(); r++)
                {
                    if (cant.empty() || f == cant.end())
                        continue;
                    if (adu[r] >= *f)
                        break;
                    if (r == adu.size() - 1)
                        r++;
                }
                l = r;
            }
            if (temp[i] != temp[i - 1] and l < adu.size())
            {
                // cout<<l;
                ok = 1;
                break;
            }
            if (temp[i] != temp[i - 1])
            {
                adu.clear();
                l = 0;
            }
        }
        if (ok == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
    }
    return 0;
}