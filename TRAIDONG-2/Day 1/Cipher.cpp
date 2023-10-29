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

int a[110];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("Cipher.inp", "r")) {
        freopen("Cipher.inp", "r", stdin);
        freopen("Cipher.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        int n = s.length();
        s = " " + s;
        for (int i = 1; i <= n; i++){
            a[i] = -1;
        }
        a[2] = s[1] - 'A';
        a[n - 1] = s[n] - 'A';
        for (int i = 4; i <= n; i+=2){
            a[i] = (s[i - 1] - 'A' - a[i - 2] + 26) % 26;
        }

        for (int i = n - 1 - 2; i >= 1; i-=2){
            a[i] = (s[i + 1] - 'A' - a[i + 2] + 26) % 26;
        }
        int ok = 1;
        for (int i = 1; i <= n; i++){
            if (a[i] == -1){
                ok = 0;
                break;
            }
        }
        if (ok ==  0){
            cout << "AMBIGUOUS" << endl;
            continue;
        }

        for (int i = 1; i <= n; i++){
            cout << char(a[i] + 'A');
        }
        cout << endl;
    }

    return 0;
}

/*
s1 = a2
s2 = a1 + a3
s3 = a2 + a4
=> a4 = s3 - a2
a6 = s5 - a4
*/