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
    int test;
    cin >> test;
    while(test--){
        int n, m, k;
        cin >> n >> m >> k;
        int x, y;
        cin >> x >> y;
        int ok = 1;
        for (int i = 1; i <= k; i++){
            int a, b;
            cin >> a >> b;
            if ((abs(a - x) + abs(b - y)) % 2 == 0){
                ok = 0;
            }
        }
        if (ok){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}