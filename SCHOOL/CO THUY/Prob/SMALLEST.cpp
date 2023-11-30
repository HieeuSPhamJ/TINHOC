#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 5 + 1e5 + 10;

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
        int sum = 0;
        int pro = 1;
        for (int i = 2; i <= n; i++){
            a[i] = 2;
        }
        a[1] = 1;
        // a[n] = 3;
        for (int i = 1; i <= n; i++){
            sum += a[i];
            pro *= a[i];
        }
        cout << sum << " " << pro << endl;
        for (int i = 1; i <= n; i++){
            cout << a[i];
        }
        cout << endl;

    }
    return 0;
}

