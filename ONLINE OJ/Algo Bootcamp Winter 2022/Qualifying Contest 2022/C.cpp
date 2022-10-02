#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int k;

int cal(int n){
    int a = (2 * k - n - 1);
    int b = (2 * n + 1);
    if (a % b == 0){
        return a / b;
    }
    return -1;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        // cout << "TEST" << endl;
        cin >> k;
        int a = -1;
        int b = -1;
        int d = 1e18;
        for (int i = 1 ; i * i <= k; i++){
            int j = cal(i);
            if (j != -1){
                int de = abs(i - j);
                if (de < d){
                    a = i;
                    b = j;
                    d = de;
                }
                // cout << i << " " << j << endl;
            }
        }
        cout << min(a, b) << " " << max(a,b);
        cout << endl;
    }
    return 0;
}
