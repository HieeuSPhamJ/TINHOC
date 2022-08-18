#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
int n;
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
        cin >> n;

        for (int i = 1; i <= n; i++){
            a[i] = i;
        }

        for (int i = n; i >= 2; i-=2){
            swap(a[i], a[i - 1]);
        }

        for (int i = 1; i <= n; i++){
            cout << a[i] << ' ';
        }

        cout << endl;
    }
    return 0;
}