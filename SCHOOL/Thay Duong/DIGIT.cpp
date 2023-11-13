#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int nxt[100];

int POW(int n, int a){
    int res = 1;
    while(a--){
        res *= n;
    }
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("DIGIT.inp", "r")) {
        freopen("DIGIT.inp", "r", stdin);
        freopen("DIGIT.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    nxt[1] = 9;
    // int sum = 9;
    for (int i = 2, t = 9; i <= 17; i++){
        nxt[i] = t * 10 * i;
        t *= 10;
        // sum += nxt[i];
    }
    // cout << sum << endl;
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int t = 1;
        while(n - nxt[t] > 0){
            n -= nxt[t];
            t++;
        }
        // cout << n << " " << t << endl;
        // cout << nxt[t] << endl;
        int s = POW(10,t - 1);
        s += n / t;
        n %= t;
        if (n == 0){
            n = t;
            s--;
        }
        // cout << s << " " << n << endl;

        vector <int> ls;
        while(s){
            ls.push_back(s % 10);
            s /= 10;
        }
        reverse(all(ls));
        // cout << n - 1 << " ";
        cout << ls[n - 1] << endl;
    }
    return 0;
}

/*


*/