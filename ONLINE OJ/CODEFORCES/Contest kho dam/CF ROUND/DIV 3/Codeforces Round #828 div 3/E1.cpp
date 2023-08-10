#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a, b, c , d;

// bool cal(long long n){
//     int curr = (a * b) / __gcd(a * b, n);
//     int x1 = b / curr + 1;
//     x1 = x1 * curr;
//     if (x1 > d){
//         return 0;
//     }
//     cout << n << ' ' << x1 << end;
//     return 1;
// }

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> a >> b >> c >> d;
        int check = 1;
        for (int i = a + 1; i <= c; i++){
            int temp = (a * b) / __gcd(a * b, i);
            int x1 = b / temp + 1;
            x1 *= temp;
            if (x1 > d){
                continue;
            }
            cout << i << ' ' << x1 << endl;
            check = 0;
            break;
        }
        if (check){
            cout << -1 << " " << -1 << endl;
        }
    }
    return 0;
}