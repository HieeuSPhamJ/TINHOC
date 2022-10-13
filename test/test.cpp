#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[100];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            for (int x = i; x <= j; x++){
                a[x]++;
            }
        }
    }
    for (int i = 1;i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 1;i < n; i++){
        cout << abs(a[i] - a[i + 1]) << " ";
    }
    return 0;
}