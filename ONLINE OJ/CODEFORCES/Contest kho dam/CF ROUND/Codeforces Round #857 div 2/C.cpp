#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    int POW = 1;
    for (int j = 1; j <= 10; j++){
        POW *= 2;
    }
    while(test--){
        int n, m;
        cin >> n >> m;
        cout << n * m << endl;
        for (int i = 1, type = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << j + type * POW << " ";
            }
            cout << endl;
            type++;
        }
    }
    
    return 0;
}