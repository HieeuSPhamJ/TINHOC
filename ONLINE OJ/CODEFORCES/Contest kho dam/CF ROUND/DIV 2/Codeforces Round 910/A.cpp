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
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            char c;
            cin >> c;
            a[i] = a[i - 1] + (c == 'B');
            // cout << a[i] << " ";
        }
        // cout << endl;
        if (a[n] == k){
            cout << 0 << endl;
            continue;
        }
        if (a[n] > k){
            cout << 1 << endl;
            for (int i = 1; i <= n; i++){
                if (a[i] == a[n] - k){
                    cout << i << " " << "A" << endl;
                    break;
                }
            }
        }
        else{
            cout << 1 << endl;
            k = k - a[n];
            for (int i = 1; i <= n; i++){
                if (i - a[i] == k){
                    cout << i << " " << "B" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}