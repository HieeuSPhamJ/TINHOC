#include <bits/stdc++.h>
using namespace std;

#define int             long long
#define uint             unsigned long long
#define fi                first
#define se                 second
#define vvi             vector< vector<int> >
#define endl             '\n'
#define pb                 push_back
#define pf                 push_front
#define all(a)             a.begin(), a.end()
#define mp                 make_pair
#define YES             cout<<"YES\n";
#define NO                 cout<<"NO\n";
#define space           ' '
#define ins             insert
typedef vector<int>     vi;
typedef pair<int, int>     pi;
int const mod         =     1e9 + 7;
int const maxn         =     5e5 + 10;
int const INF         =     LLONG_MAX;

int n, a[5010] = {};
set<int> s[maxn] = {};
void solve() {
    cin >> n;
    int cnt = 0;
    cin >> a[1];
    for(int i = 2; i <= n; i++) {
        cin >> a[i];
        bool exist = 0;
        for(int j = i - 1; j > 1; j--) {
            if(s[j].count(a[i] - a[j]) != 0) {
                exist = 1;
                s[i].insert(a[i] - a[j]);
            }
        }
        if(!exist) {
            cnt++;
            s[i].ins(a[i] - 1);
        }
    }
    cout << cnt;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
     solve();
}