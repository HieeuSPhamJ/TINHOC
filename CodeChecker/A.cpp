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

const int maxN = 1e6 + 10;

int mk[maxN];
int le[maxN];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        mk[x] = 1;
    }

    for (int i = 1; i < maxN; i++){
        if (mk[i - 1]){
            le[i] = i - 1;
        }
        else{
            le[i] = le[i - 1];
        }
    }
    int res = 0;
    for (int i = 1; i < maxN; i++){
        if (mk[i]){
            for (int j = 2 * i; j < maxN; j += i){
                // cout << le[j] << ' ' << i << endl;
                if (le[j] >= i){
                    res = max(res, le[j] % i);
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}

/*
a[i]
a[j] % a[i] = k
k < a[i]
k 

*/