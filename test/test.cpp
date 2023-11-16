#include <bits/stdc++.h>
using namespace std;
#define lll pair<pair<long, long>, long>
#define st first
#define nd second
const long N = 1e7 + 7;
const long M = 3e5 + 10;
const long oo = (1 << 19);
long n, q, A[M], F[N], ans[50007], l, r, x, y, dem, B[oo + 10], pos0;
map<long, long> pos;
vector<long> ds, d;
lll Q[50007];
void update(long a, long val)
{
    for (; a <= oo; a += a & (-a))
        B[a] += val;
}
long get(long a)
{
    if (!a)
        return 0;
    long cnt = 0;
    for (; a >= 1; a -= a & (-a))
        cnt += B[a];
    return cnt;
}
long xuly(long a)
{
    if (!a)
        return 0;
    long so = 1;
    while (a > 1)
    {
        if (ds.empty() || F[a] != ds.back())
        {
            ds.push_back(F[a]);
            d.push_back(1);
        }
        else
            d[d.size() - 1]++;
        a /= F[a];
    }
    for (long i = 0; i < ds.size(); i++)
    {
        if (d[i] % 2 != 0)
        {
            so *= ds[i];
        }
    }
    ds.clear();
    d.clear();
    return so;
}
bool cmp(lll a, lll b)
{
    return a.st.nd < b.st.nd;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    F[1] = 1;
    for (long i = 2; i * i <= 10000000; i++)
    {
        if (!F[i])
        {
            for (long j = i * i; j <= 10000000; j += i)
            {
                if (!F[j])
                    F[j] = i;
                else
                    F[j] = min(F[j], i);
            }
        }
    }
    for (long i = 2; i <= 10000000; i++)
    {
        if (!F[i])
            F[i] = i;
    }
    cin >> n >> q;
    for (long i = 1; i <= n; i++)
    {
        cin >> A[i];
        if (A[i] < 0)
            A[i] = -xuly(abs(A[i]));
        else
            A[i] = xuly(A[i]);
    }
    for (long i = 1; i <= q; i++)
    {
        cin >> Q[i].st.st >> Q[i].st.nd;
        Q[i].nd = i;
    }
    sort(Q + 1, Q + q + 1, cmp);
    l = 1;
    for (long i = 1; i <= n; i++)
    {
        if (pos[A[i]])
        {
            update(pos[A[i]], -1);
        }
        update(i, 1);
        pos[A[i]] = i;
        pos0 = pos[0];
        while (l <= q && Q[l].st.nd == i)
        {
            ans[Q[l].nd] = get(Q[l].st.nd) - get(Q[l].st.st - 1);
            if (Q[l].st.st <= pos0 && ans[Q[l].nd] > 1)
                ans[Q[l].nd]--;
            l++;
        }
    }
    for (long i = 1; i <= q; i++)
        cout << ans[i] << '\n';

    return 0;
}