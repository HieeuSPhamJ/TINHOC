#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int lcm(int a, int b){
    return a * b / __gcd(a,b);
}

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
        int a, b;
        cin >> a >> b;
        if (a == 1){
            cout << b * b << endl;
        }
        else{
            int t = min(a,b);
            for (int i = 2; i * i <= a; i++){
                if (a % i == 0){
                    t = min(t,i);
                    // cout << i << " ";
                    break;
                }
            }
            for (int i = 2; i * i <= b; i++){
                if (b % i == 0){
                    t = min(t,i);
                    // cout << i << " ";
                    break;
                }
            }

            cout << max(a,b) * t << endl;

        }
    }
    return 0;
}