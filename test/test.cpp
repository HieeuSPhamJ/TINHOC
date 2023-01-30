#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
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
        double a,b,c,x,y,z;
        cin >> a >> b >> c >> x >> y >> z;
        double adu1 = a * b / c;
        double adu2 = x * y / z;

        if (adu1 == adu2){
            cout << "=";
        }
        else if (adu1 < adu2){
            cout << "<";
        }
        else {
            cout << ">";
        }
        cout << endl;
    }
    return 0;
}