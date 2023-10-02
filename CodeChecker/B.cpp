/*
Good luck for those who are trying your best
May the most glorious victory come
File name: TIEPTHI.cpp
Code by : acident / lckintrovert
Created since : 21/09/2023 ~~ 17:15:42
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int                  long long
#define uint                 unsigned long long
#define dub                  double
#define fi                   first
#define se                   second
#define endl                 '\n'
#define pb                   push_back
#define pf                   push_front
#define eb                   emplace_back
#define ins                  insert
#define mp                   make_pair
#define all(a)               a.begin(), a.end()
#define YES                  cout << "YES\n"
#define NO                   cout << "NO\n"
#define coutdub(x)           cout << fixed << setprecision(x)
#define cerrdub(x)           cerr << fixed << setprecision(x)

//#define _USE_MATH_DEFINES // If meth .__.

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pi>           vp;
const int mod       =        1e9 + 7;
const int maxn      =        1e5 + 10;
const int INF       =        1e15;

int n, pre, u, v, cur = 0;
map<int, int> m;
vector<pi> a;
inline void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> u >> v;
        m[u]++; m[v]--;
    }
    int ans = 0, pre = 0, couting;
    for(auto s : m) {
        cur += s.se;
        if(maximize(ans, cur)) {
            couting = s.fi;
        }
        if(pre != s.fi) a.pb(mp(pre, s.fi));
        pre = s.fi;
    }
    cout << ans << endl;
    for(auto s : a) if(s.fi == couting) {cout << s.fi << ' ' << s.se; return;}
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    solve();
}

/*A place to scribble thoughts

*/