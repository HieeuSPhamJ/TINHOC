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

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("ghh.inp", "r")) {
        freopen("ghh.inp", "r", stdin);
        freopen("ghh.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 1; i * i <= n; i++){
            if (n % i == 0){
                sum += i;
                if (n / i != i){
                    sum += n / i;
                }
            }
        }

        cout << (n * 2 <= sum) << endl;
    }
    return 0;
}