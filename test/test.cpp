/*
Good luck for those who are trying your best
May the most glorious victory come
File name: I.cpp
Code by : acident / lckintrovert
Created since : 12/09/2023 ~~ 12:23:43
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define endl                '\n'
#define pb                  push_back
#define pf                  push_front
#define eb                  emplace_back
#define ins                 insert
#define mp                  make_pair
#define all(a)              a.begin(), a.end()
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define coutdub(x)          cout << fixed << setprecision(x)
#define cerrdub(x)          cerr << fixed << setprecision(x)
 
//#define _USE_MATH_DEFINES // If meth .__.
 
template<class T1, class T2> void maximize(T1& a, T2 b) {a = max(a, b);}
template<class T1, class T2> void minimize(T1& a, T2 b) {a = min(a, b);}
template<class T1> T1 abs(T1 a) {return max(a, -a);}
 
typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e6 + 10;
 
vi p(maxn);
int find(int k) {
    if(k == p[k]) return k;
    return p[k] = find(p[k]);
}
void connect(int u, int v) {
    u = find(u); v = find(v);
    p[u] = v;
}

int r, c, x;
priority_queue<pi, vector<pi>, greater<pi> > q;
void solve() {
    cin >> r >> c;
    p.resize(r + c + 10);
    for(int i = 1; i <= r + c; i++) p[i] = i;
    for(int i = 1; i <= r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> x;
            q.push(mp(x, i * c + j));
        }
    }
    int x, y, ans = 0, price;
    while(!q.empty()) {
        x = q.top().se / c; 
        y = q.top().se % c + 1 + r;
        price = q.top().fi;
        q.pop();
        if(find(x) == find(y)) continue;
        else {
            cout << x << " " << y << endl;
            ans += price;
            connect(x, y);
        }
    }
    cout << ans;

}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}

/*A place to scribble thoughts
...O1
....2
.O.O3
....4
.O..5
6789
*/