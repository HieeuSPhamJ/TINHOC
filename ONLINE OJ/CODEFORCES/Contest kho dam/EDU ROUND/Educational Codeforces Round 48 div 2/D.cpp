#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int h[110];
int c[110];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    int axor = 0, bxor = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        axor = axor xor a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
        bxor = bxor xor b[i];
    }
    if (axor != bxor){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << (b[0] xor axor xor a[0]) << " ";
        for (int j = 1; j < m; j++){
            cout << b[j] << " ";
        }
        cout<< endl;
        for (int i = 1; i < n; i++) {
            cout << a[i] << " ";
            for (int j = 1; j < m; j++){
                cout << "0 ";
            }
            cout << endl;
        }
    }
    return 0;
}