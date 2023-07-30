#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

pair <ii,int> a[maxN];
int res[maxN];

signed main(){
    // freopen("KILL.INP", "r", stdin);
    // freopen("KILL.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi.fi;
        a[i].se = i;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi.se;
    }

    sort(a + 1, a + 1 + n);

    priority_queue <int, vector <int>, greater<int>> q;

    for (int i = 1, s = 0; i <= n; i++){
        res[a[i].se] += s + a[i].fi.se;
        s += a[i].fi.se;
        q.push(a[i].fi.se);
        while(q.size()> k){
            s -= q.top();
            q.pop();
        }
    }
    
    for (int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }

    return 0;
}
