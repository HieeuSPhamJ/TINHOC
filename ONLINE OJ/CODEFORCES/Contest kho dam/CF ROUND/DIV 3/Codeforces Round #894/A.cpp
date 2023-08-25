#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

char a[1100][1100];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        string s = "vika";
        int ok = 0;
        for (int j = 1, cnt = 0; j <= m; j++){
            for (int i = 1; i <= n; i++){
                if (a[i][j] == s[cnt]){
                    cnt++;
                    break;
                }
            }
            if (cnt == 4){
                ok = 1;
                cout << "YES";
                goto bru;
            }
        }
        cout << "NO";
        bru:;
        cout << endl;
    }
    return 0;
}