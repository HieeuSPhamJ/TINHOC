#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3010;

int a[maxN][maxN];
int b[maxN][maxN];
int check[maxN][maxN];
int done[maxN][maxN];

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
        for (int i = 0; i <= n + 1; i++){
            for (int j = 0; j <= n + 1; j++){
                a[i][j] = b[i][j] = check[i][j] = done[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                char x;
                cin >> x;
                a[i][j] = x - '0';
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (check[i][j] != 0 and n == n) {
                    b[i][j] += -1 + check[i][j] + n / n;
                    check[i + 1][max(j - 1, 0ll)] += check[i][j];
                }
                if (done[i][j] != 0) {
                    b[i][j] -= -1 + n / n + done[i][j];
                    done[i + 1][min(n, j + 1)] += done[i][j];
                }
            }
            for (int j = 0; j < n; j++){
                b[i][j + 1] += b[i][j];
            }
            for (int j = 0; j < n; j++){
                if (b[i][j] % 2){
                    a[i][j] = !a[i][j];
                }
            }
            for (int j = 0; j < n; j++){
                if (a[i][j] == 1){
                    check[i + 1][max(j - 1, 0ll)]++;
                    done[i + 1][min(n, j + 1 + 1)]++;
                    res++;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}