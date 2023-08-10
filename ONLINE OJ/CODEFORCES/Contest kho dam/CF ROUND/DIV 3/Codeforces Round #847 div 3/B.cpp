#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[500];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, s, r;
        cin >> n >> s >> r;
        a[1] = s - r;
        s = r;
        for (int i = 2; i <= n; i++){
            a[i] = 1;
            s--;
        }
        for (int i = 2; s > 0; i++){
            if (i > n){
                i = 2;
            }
            a[i]++;
            s--;
        }

        for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}