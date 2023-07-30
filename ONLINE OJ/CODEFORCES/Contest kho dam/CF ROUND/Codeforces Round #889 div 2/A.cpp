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
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if (x == i){
                cnt++;
            }
        }
        if (cnt == 0){
            cout << 0 << endl;
            continue;
        }
        cout << (cnt - 1) / 2 + 1 << endl;
    }
    return 0;
}