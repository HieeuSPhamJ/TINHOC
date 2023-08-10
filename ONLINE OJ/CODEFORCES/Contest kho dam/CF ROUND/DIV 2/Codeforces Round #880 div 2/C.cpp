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
        int a, b, c, k;
        cin >> a >> b >> c >> k;
        int maa = pow(10,a) - 1;
        int mia = pow(10,a - 1);

        int mab = pow(10,b) - 1;
        int mib = pow(10,b - 1);

        int mac = pow(10,c) - 1;
        int mic = pow(10,c - 1);

        for (int i = mia; i <= maa; i++){
            int t1 = max(mic - i, 1ll);
            int t2 = mac - i;
            if (t1 <= t2 and t1 <= mab and t2 >= mib){
                t1 = max(t1, mib);
                t2 = min(t2, mab);
                int t = t2 - t1 + 1;
                // cout << i << " " << t << endl;
                if (k - t <= 0){
                    cout << i << " + " << t1 + k - 1 << " = " << i + t1 + k - 1 << endl;
                    goto bru;
                }
                k -= t;
            }            
        }
        cout << -1 << endl;
        bru:;
    }
    return 0;
}

/*
if (t1 <= mab and t2 >= mib)
*/