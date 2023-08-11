#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int n, m, k;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    int p = n * m;
    int g = __gcd(p, k);
    k /= g;
    if (k > 2){
        cout << "NO" << endl;
        return 0;
    }
    // cout << k << " " << g << endl;
    if (k == 2){
        int a = n / __gcd(n,g);
        g /= __gcd(n,g);
        int b = m / __gcd(m,g);
        cout << "YES" << endl;
        cout << 0 << ' ' << 0 << endl;
        cout << a << ' ' << 0 << endl;
        cout << 0 << ' ' << b << endl;
    }
    else{
        int ta = n / __gcd(n,g);
        g /= __gcd(n,g);
        int tb = m / __gcd(m,g);
        // cout << p << " " << g << endl;
        // cout << ta << " " << tb << endl;
        if (ta * 2 <= n){
            ta *= 2;
        }
        else if (tb * 2 <= m){
            tb *= 2;
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        cout << 0 << ' ' << 0 << endl;
        cout << ta << ' ' << 0 << endl;
        cout << 0 << ' ' << tb << endl;
    }
    return 0;
}

/*
1000000000 
1000000000 
*/