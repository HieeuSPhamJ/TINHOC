#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];

bool cmp(int a, int b){
    return a > b;
}

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
        sort(a + 1, a + 1 + n, cmp);
        int ok = 1;
        if (a[n] == a[1]){
            ok = 0;
        }
        else{
            if (a[1] == a[2]){
                swap(a[2], a[n]);
            }
        }

        

        if (ok){
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}