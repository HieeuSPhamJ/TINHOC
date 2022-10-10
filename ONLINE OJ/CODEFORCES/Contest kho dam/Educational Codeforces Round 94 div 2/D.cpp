#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 3010;

int a[maxN];
int prefix[maxN][maxN];

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
            for (int i = 1; i <= n; i++){
                prefix[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++){
            cin >> a[i];
            prefix[i][a[i]]++;
        }
        
        int ans = 0;

        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                if (a[i] != a[j]){
                    continue;
                }
                
            }
        }

        cout << ans << endl;

    }
    return 0;
}