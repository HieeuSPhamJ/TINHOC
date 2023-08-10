#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int b[maxN];

int gcd(int a, int b){
    if (a < b){
        return gcd(b, b - a) + 1;
    }
    int t = a / b;
    t += (a / b) / 2 + (a - b < b);
    return t + gcd(a - t * b, a - b);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    cout << gcd(100, 1245);
    // while(test--){
    //     int n;
    //     cin >> n;
    //     for (int i = 1; i <= n; i++){
    //         cin >> a[i];
    //     }
    //     set <int> s;
    //     for (int i = 1; i <= n; i++){
    //         cin >> b[i];
    //         s.insert(gcd(a[i],b[i]));
    //     }
    //     if (s.size() == 1){
    //         cout << "YES";
    //     }
    //     else{
    //         cout << "NO";
    //     }
    //     cout << endl;

        
    // }
    return 0;
}