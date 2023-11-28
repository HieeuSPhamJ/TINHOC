#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1510;

int a[maxN];
unordered_map <int,int> cnt;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++){
            cnt[a[i] - a[j]]++;
        }
    }
    for (int i = 1; i <= m; i++){
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j < i; j++){
            res += cnt[a[i] - a[j]];
        }
    }
    cout << res << endl;
    return 0;
}