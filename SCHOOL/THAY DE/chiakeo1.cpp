#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int a[110];
int res[110];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("chiakeo1.inp", "r")) {
        freopen("chiakeo1.inp", "r", stdin);
        freopen("chiakeo1.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set <int> s;
    s.insert(1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        res[i] = 1e18;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        int u = 1;
        while(a[i] / u){
            u = a[i] / (a[i] / u) + 1;
            s.insert(u);
        }
    }

    vector <int> ls;

    for (auto i: s){
        // cout << i << " ";
        ls.push_back(i);
    }
    // cout << endl;


    for (auto x: ls){
        ii va = {-1,-1};
        // cout << "With: " << x << endl;
        for (int i = 1; i <= n; i++){
            // cout << a[i] / x << endl;
            if (va.se == a[i] / x){
                va.fi++;
            }
            else{
                if (va.fi != -1){
                    // cout << va.fi << " " << x << endl;
                    res[va.fi] = min(res[va.fi], x);
                    
                }
                va.fi = 1;
                va.se = a[i] / x;
            }
        }
        // cout << va.fi << " " << x << endl;
        res[va.fi] = min(res[va.fi], x);

        // for (int j = 1; j <= n; j++){
        //     if (res[j] == 1e18){
        //         cout << -1 << " ";
        //         continue;
        //     }
        //     cout << res[j] << " ";
        // }
        // cout << endl;
    }

    for (int i = 1; i <= n; i++){
        if (res[i] == 1e18){
            cout << -1 << endl;
        }
        else{
            cout << res[i] << endl;
        }
    }
    return 0;
}

/*

*/