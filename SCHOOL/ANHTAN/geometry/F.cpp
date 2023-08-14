#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int area(ii a, ii b, ii c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se);
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
        ii a, b, c;
        cin >> a.fi >> a.se >> b.fi >> b.se >> c.fi >> c.se;
        int s = area(a,b,c);
        if (s == 0){
            cout << "TOUCH" << endl;
        }
        else if (s < 0){
            cout << "RIGHT" << endl;
        }
        else{
            cout << "LEFT" << endl;
        }
    }
    return 0;
}