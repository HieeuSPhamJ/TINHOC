#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = a * d;
        int y = b * c;
        if (x == y){
            cout << 0 << endl;
            continue;
        }
        if (x < y){
            swap(x,y);
        }
        // cout << x << " " << y << endl;
        if (min(x,y) == 0 or x % y == 0){
            cout << 1 << endl;
            continue;
        }
        cout << 2 << endl;

    }
    return 0;
}