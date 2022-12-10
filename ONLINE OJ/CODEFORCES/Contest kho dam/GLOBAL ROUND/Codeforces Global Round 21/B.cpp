#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = 0 ;
        vector<int> a(n + 1);
        for (int i = 1 ; i <= n ;i ++) {
            cin >> a[i];
            if (!a[i]) cnt++;
        }
        int l = 0 , r = 0;
        for (int i = 1 ; i <= n ;i ++) {
            if (!a[i]) l++;
            else break;
        }
        for (int i = n ; i >= l ; i--) {
            if (!a[i]) r++; 
            else break; 
        }
        if (cnt == n) {
            cout << 0;
        }
        else if (cnt == (l + r)) {
            cout << 1;
        }
        else {
            cout << 2;
        }
        cout << endl;
    }
    return 0;
}