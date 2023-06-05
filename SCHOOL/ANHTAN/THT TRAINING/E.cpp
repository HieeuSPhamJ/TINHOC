#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, ak, bk, k;
    cin >> n >> m >> ak >> bk >> k;

    if(k >= min(n,m)){
        cout << -1 << endl;
        return 0;
    }

    vector <int> a,b;
    
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        x += ak;
        a.push_back(x);
    }
    for (int i = 1; i <= m; i++){
        int x;
        cin >> x;
        b.push_back(x);
    }
    
    int ia = 0;
    int ib = 0;
    int res = -1e18;
    int k0 = k;
    k++;
    while(k--){
        while(ib < m and a[ia] > b[ib]){
            ib++;
        }
        if (ib + k0 - ia >= m){
            res = -1;
            break;
        }
        if (ib + (k0 - ia)  >= m){
            res = -1;
            break;
        }
        res = max(res, b[ib + k0 - ia] + bk);
        ia++;
    }
    cout << res << endl;

    return 0;
}

/*
2 4 6 8
1 2 3 9 10

2 4 6 8
2 3 9 10


*/