#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN =1e5 + 10;

int a[maxN];

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
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int pt = n;
        a[0] = 0;
        while (a[pt] == a[pt - 1]){
            pt--;
        }
        if (pt == 1){
            cout << -1 << endl;
        }
        else{
            cout << pt - 1 << ' ' << n - pt + 1 << endl;
            for (int i = 1; i < pt; i++){
                cout << a[i] << ' ';
            }
            cout << endl;
            for (int j = pt; j <= n; j++){
                cout << a[j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}