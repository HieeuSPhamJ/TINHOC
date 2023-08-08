/**
 * File              : c.cpp
 * Author            : hungeazy
 * Date              : 05.08.2023
 * Last Modified Date: 05.08.2023
 * Last Modified By  : hungeazy
 */
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ull unsigned long long
#define sz(x) x.size()
#define sqr(x) (1LL * (x) * (x))
#define all(x) x.begin(), x.end()
#define fill(f,x) memset(f,x,sizeof(f))
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
#define ii pair<int,int>
#define iii pair<int,ii>
#define vi vector<int>
#define mii map<int,int>
#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define __lcm(a,b) (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define MASK(i) (1LL << (i))
#define c_bit(i) __builtin_popcountll(i)
#define BIT(x,i) ((x) & MASK(i))
#define SET_ON(x,i) ((x)  MASK(i))
#define SET_OFF(x,i) ((x) & ~MASK(i))
#define oo 1e18
#define name ""
#define time() cout << "-------------Time:" << 1000.0 * clock() / CLOCKS_PER_SEC << "ms.";
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
int a[(int)1e6+10],n,k;

int check(int mid)
{
    FOR(i,1,n)
        if (a[i] >= mid) return true;
    int cnt;
    FOR(i,1,n-1)
    {
        cnt = 0;
        FOR(j,i,n)
        {
            if (j == n)
            {
                if (a[n] >= mid-n+i) return true;
                cnt = k+1;
                break;
            }
            if (a[j] >= mid-j+i) return true;
            cnt += ((mid-j+i)-a[j]);
            if (cnt > k) break;
        }
        if (cnt > k) continue;
        else return true;
    }
    return false;
}


main()
{
    fast;
    /*freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);*/
    int t;
    cin >> t;
    while (t--)
    {
        int ans,m=-oo;
        cin >> n >> k;
        FOR(i,1,n) cin >> a[i], m = max(m,a[i]);
        int l = m, r = 1e18;
        while (l <= r)
        {
            int mid = (l+r)/2;
            if (check(mid)) ans = mid, l = mid+1;
            else r = mid-1;
        }
        cout << ans << '\n';
    }
    return 0;
}
// ██░ ██  █    ██  ███▄    █   ▄████
//▓██░ ██▒ ██  ▓██▒ ██ ▀█   █  ██▒ ▀█▒
//▒██▀▀██░▓██  ▒██░▓██  ▀█ ██▒▒██░▄▄▄░
//░▓█ ░██ ▓▓█  ░██░▓██▒  ▐▌██▒░▓█  ██▓
//░▓█▒░██▓▒▒█████▓ ▒██░   ▓██░░▒▓███▀▒
// ▒ ░░▒░▒░▒▓▒ ▒ ▒ ░ ▒░   ▒ ▒  ░▒   ▒
// ▒ ░▒░ ░░░▒░ ░ ░ ░ ░░   ░ ▒░  ░   ░
// ░  ░░ ░ ░░░ ░ ░    ░   ░ ░ ░ ░   ░
// ░  ░  ░   ░              ░       ░