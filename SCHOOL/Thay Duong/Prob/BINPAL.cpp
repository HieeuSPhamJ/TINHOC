#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool getBit(int mask, int i)
{
    return (mask & (1ll << i));
}

int onBit(int mask, int i)
{
    return mask | (1ll << i);
}

int offBit(int mask, int i)
{
    if (getBit(mask, i))
    {
        return (mask xor (1ll << i));
    }
    return mask;
}

int flipBit(int mask, int i)
{
    return (mask xor (1ll << i));
}

int countBits(int mask)
{
    int count = 0;
    while (mask)
    {
        count += (mask & 1);
        mask >>= 1;
    }
    return count;
}

signed main()
{
    // freopen("BINPAL.INP", "r", stdin);
    // freopen("BINPAL.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, ans, k, so, z;
    string s, s2, s3, s4;
    bool OK;
    vector<int> q;
    cin >> t;
    q.push_back(1);
    q.push_back(0);
    for (int i = 1; i <= (1ll << 16); i++)
    {
        s.clear();
        for (int j = 0; j <= 16; j++)
        {
            if ((i & (1ll << j)))
                k = j;
        }
        for (int j = k; j >= 0; j--)
        {
            if ((i & (1l << j)))
                s += '1';
            else
                s += '0';
        }
        s2 = s;
        s3 = s;
        s4 = s;
        reverse(s.begin(), s.end());
        s2 += s;
        s3 += '0' + s;
        s4 += '1' + s;
        // if(i==10) cout<<s2;
        reverse(s2.begin(), s2.end());
        reverse(s3.begin(), s3.end());
        reverse(s4.begin(), s4.end());
        so = 0;
        for (int j = 0; j < s2.size(); j++)
            if (s2[j] == '1')
                so += (1ll << j);
        q.push_back(so);
        so = 0;
        for (int j = 0; j < s3.size(); j++)
            if (s3[j] == '1')
                so += (1ll << j);
        q.push_back(so);
        so = 0;
        for (int j = 0; j < s4.size(); j++)
            if (s4[j] == '1')
                so += (1ll << j);
        // cout<<so<<' ';
        q.push_back(so);
    }
    sort(q.begin(), q.end());
    // for(int i=0; i<=10; i++) cout<<q[i]<<' ';
    // cout<<q.back();
    
    while (t--)
    {
        cin >> n;
        z = upper_bound(q.begin(), q.end(), n) - q.begin();
        // cout<<q[z]<<' '<<q[z-1];
        ans = min(q[z] - n, n - q[max(0ll, z - 1)]);
        cout << ans << '\n';
    }

    return 0;
}