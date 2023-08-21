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

int a[maxN];

void cmp(ii x, ii y){
    return max(a[x.fi],a[x.se]) < max(a[y.fi], a[y.se]);
}

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
    vector <ii> ls;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        ls.push_back({a,b});
    }

    sort(all(ls), cmp);
    return 0;
}