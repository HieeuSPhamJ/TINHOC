#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("paint.inp", "r")) {
        freopen("paint.inp", "r", stdin);
        freopen("paint.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x > y){
        swap(x,y);
    }
    if (a > b){
        swap(a,b);
    }
    if (x > a){
        swap(x,a);
        swap(y,b);
    }
    if (b <= y){
        cout << y - x;
        return 0;
    }
    if (y <= a){
        cout << b - a + y - x;
        return 0;
    }
    cout << b - x;
    return 0;
}