//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define emotion "Chu he thoi dai"
#define taskname "blabla"
#define endl "\n"
#define fi first
#define se second
#define int long long
#define FangIo_oI top1

using namespace std;
typedef pair <int, int> ii;
typedef pair <ii, int> iii;

int n, q;
bool f;
deque <iii> ls;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;
    f = true;
    for (int qeri = 1; qeri <= q; ++ qeri)
    {
        int state;
        cin >> state;
        if (state == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            if (f)
            {
                ls.push_front(iii(ii(l, r), x));
            }
            else
            {
                ls.push_back(iii(ii(l, r), x));
            }
            f = 1 - f;
        }
        else
        {
            int res = 0, l, r;
            cin >> l >> r;
            for (int i = 0; i < ls.size(); ++ i)
            {
                int left = ls[i].fi.fi;
                int right = ls[i].fi.se;
                left = max(l, left);
                right = min(r, right);
                int v = ls[i].se;
                if (left <= right && ((right - left) & 1) == 0)
                {
                    res = res ^ v;
                }
            }
            cout << res << endl;
            while(!ls.empty())
            {
                ls.pop_front();
            }
        }
    }
    return 0;
}