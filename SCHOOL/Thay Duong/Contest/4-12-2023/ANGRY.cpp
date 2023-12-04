#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("angry.in", "r")) {
        freopen("angry.in", "r", stdin);
        freopen("angry.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    int res = 0;
    for (int i = 1; i <= n; i++){
        int tres = 1;
        // cout << "With: " << i << endl;
        for (int j = i + 1, cnt = 1, ok = 0, la = i; j <= n;){
            if (a[j] - a[la] <= cnt){
                // cout << a[j] << " " << cnt << endl;
                tres++;
                ok = 1;
                j++;
            }
            else if (ok){
                cnt++;
                ok = 0;
                la = j - 1;
            }
            else{
                break;
            }
        }
        for (int j = i - 1, cnt = 1, ok = 0, la = i; j >= 1;){
            if (a[la] - a[j] <= cnt){
                // cout << a[j] << " " << cnt << endl;
                tres++;
                ok = 1;
                j--;
            }
            else if (ok){
                cnt++;
                ok = 0;
                la = j + 1;
            }
            else{
                break;
            }
        }
        // cout << i << ": " << tres << endl; 
        res = max(res, tres);
    }
    cout << res << endl;
    return 0;
}
/*

1 3 4 5 6 8 9 10 17 19 20 22 24 25 26 28 29 30 31 33 39 41 42 43 44 45 47 48 54 55 56 58 60 61 63 69 70 71 72 73 75 76 77 79 

1234567890123
..xxxx.x....x
*/