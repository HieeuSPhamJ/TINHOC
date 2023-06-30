#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int what_day = 365;
    int freq = 30;
    int add = 1000000;
    double base = 1000000;
    double rate = 6.0 / 365;
    for (int day = 1; day <= what_day; day++){
        if (day % freq == 0){
            base += add;
        }
        base = base * (100 + rate) / 100;
        cout << fixed << setprecision(2) << "Day " << day << ": " << base << endl;
    }
    return 0;
}