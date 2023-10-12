#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[1010][1010];
int b[1010][1010];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                char x;
                cin >> x;
                a[i][j] = x - 'a';
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                int t = a[i][j];
                t = max(t, a[j][n - i + 1]);
                t = max(t, a[n - j + 1][i]);
                t = max(t, a[n - i + 1][n - j + 1]);
                b[i][j] = b[j][n - i + 1] = b[n - j + 1][i] = b[n - i + 1][n - j + 1] = t;
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                // cout << b[i][j] << " ";
                res += b[i][j] - a[i][j];
            }
            // cout << endl;
        }
        cout << res << endl;
    }    
    return 0;
}

/*
bbaa
abba
aaba
abba


bbbb
bbbb
bbbb
bbbb

i, j
n - i + 1, n - j + 1
n - j + 1, i
j, n - i + 1

1 2
4 3
3 1
2 4
*/