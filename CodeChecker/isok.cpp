#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[10000];
int b[10000];


signed main(){
    freopen("A.out", "r", stdin);
    freopen("isok.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    if (n == -1){
        cout << "ok";
        return 0;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }
    int d1 = a[2] - a[1];
    int d2 = b[2] - b[1];
    for (int i = 2; i <= n; i++){
        if (a[i] - a[i - 1] != d1){
            cout << "dark";
            return 0;
        }
    }
    for (int i = 2; i <= m; i++){
        if (b[i] - b[i - 1] != d2){
            cout << "dark";
            return 0;
        }
    }
    cout << "ok";
    return 0;
}