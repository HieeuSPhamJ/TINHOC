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

const int maxN = 1e5 + 10;

map <char,char> cv;

int a[maxN];

int cal(int n){
    return n * (n - 1) / 2 + n;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("tbrackets.inp", "r")) {
        freopen("tbrackets.inp", "r", stdin);
        freopen("tbrackets.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cv['{'] = '!';
    cv['['] = '!';
    cv['('] = '!';
    cv['<'] = '!';
    cv['}'] = '{';
    cv[']'] = '[';
    cv[')'] = '(';
    cv['>'] = '<';
    
    string s;
    cin >> s;
    int n = s.length();
    s = " " + s;
    for (int i = 2; i <= n; i++){
        int c = s[i];
        if (s[i - 1] == cv[c]){
            a[i] = 1;
            a[i - 1] = -1;
        }
    }

    for (int i = 1; i <= n; i++){
        if (a[i] == 0 and a[i - 1] != 0){
            int d = a[i - 1];
            int la = i - 2 * d - 1;
            if (la > 0 and s[la] == cv[s[i]]){
                a[la] = - (d + 1);
                a[i] = d + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        a[i] = -a[i];
        // cout << a[i] << " ";
    }
    // cout << endl;

    int res = 0;
    int cnt = 0;
    for (int i = 1; i <= n;){
        if (a[i] == 0){
            // cout << "!" << i << " " << cnt << endl;
            res += cal(cnt);
            cnt = 0;
            i++;
        }
        else{
            // cout << i << " " << a[i] - 1 << endl;
            cnt++;
            res += a[i] - 1;
            i += 2 * a[i];
        }
    }
    res += cal(cnt);
    cout << res << endl;

    return 0;   
}