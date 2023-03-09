#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define _sort(x) sort(all(x))
#define loop(i, N) for (int i = 0; i < N; i++)
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

void solve()
{
    int n;
    cin >> n;

    vpi arr(n);
    loop(i, n) cin >> arr[i].first >> arr[i].second;
    _sort(arr);

    vi suf(n + 1, -1);
    suf[n - 1] = arr[n - 1].second;
    for (int i = n - 2; i >= 0; i--)
        suf[i] = max(suf[i + 1], arr[i].second);

    set<int> st;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int mx = suf[i + 1];
        if (i != n - 1)
            ans = min(ans, abs(mx - arr[i].first));

        if (mx < arr[i].first && !st.empty())
        {
            auto curr = st.upper_bound(arr[i].first);
            if (curr == st.end())
            {
                curr--;
                ans = min(ans, abs(*curr - arr[i].first));
            }
            else
            {
                ans = min(ans, abs(*curr - arr[i].first));
                if (curr != st.begin())
                {
                    curr--;
                    ans = min(ans, abs(*curr - arr[i].first));
                }
            }
        }
        st.insert(arr[i].second);
    }
    cout << ans << endl;
}

int32_t main()
{
    int T = 1;
    cin >> T;

    while (T--)
        solve();
}