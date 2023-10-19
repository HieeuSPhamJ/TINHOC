#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int n, k;
int res = 0;

int a[1000];
int color[1000];

void backtrack(int id){
    if (id >= n){
        for (int i = 1; i <= n; i++){
            if (a[i] != i){
                if (color[i] == color[a[i]]){
                    return;
                }
            }
        }
        for (int i = 1; i <= n; i++){
            cout << color[i] << " ";
        }
        cout << endl;
        res++;
        return;
    }
    for (int t = 1; t <= k; t++){
        color[id + 1] = t;
        backtrack(id + 1);
    }
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    // cout << n << " " << k << endl;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    backtrack(0);

    cout << res << endl;
    return 0;
}