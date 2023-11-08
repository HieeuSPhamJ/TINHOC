#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define cc pair<char,char>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 110;

string a[maxN];
int cnt1[2];
int cnt0[2];

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
        memset(cnt0,0,sizeof(cnt0));
        memset(cnt1,0,sizeof(cnt1));
        string s, t;
        cin >> s >> t;
        int n = 0;

        int res = 0;
        for (int i = 1; i <= (int)s.length(); i++){
            if (s[i - 1] == '?'){
                res += (s[i - 1] == '?');
                continue;
            }
            if (s[i - 1] == t[i - 1]){
                continue;
            }

            n++;
            a[n] = "";
            a[n] += s[i - 1];
            a[n] += t[i - 1];
            for (int j = 0; j <= 1; j++){
                if (a[n][j] == '1'){
                    cnt1[j]++;
                }
                if (a[n][j] == '0'){
                    cnt0[j]++;
                }
            }
        }
        if (n == 0){
            cout << res << endl;
            continue;
        }
        // cout << cnt0[0] << " " << cnt1[0] << endl;
        // cout << cnt0[1] << " " << cnt1[1] << endl;
        
        if (cnt1[0] <= cnt1[1]){
            int t = cnt1[1] - cnt1[0];
            res += t;
            cnt1[1] -= t;
            cnt0[0] -= t;
            res += cnt0[0];
            cout << res << endl;
            continue;
        }

        cout << -1 << endl;
    }

    return 0;
}
/*
?1?
001

*/