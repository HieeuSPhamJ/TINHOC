#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double ab,bc,a,b,c;
    cin >> ab >> bc >> a >> b >> c;
    /*
    v =s/t
    t = s/v
    */
    double ac = ab + bc;

    double t = ac / (c + a);

    cout << fixed << setprecision(4) << b * t;
    return 0;
}