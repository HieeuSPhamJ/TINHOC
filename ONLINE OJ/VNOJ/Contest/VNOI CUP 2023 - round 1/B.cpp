#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

double cal(double a, double b){
    double v = a + b;
    double ts = 10 / b;
    double t = 100 / v;

    if (t > ts){
        double ss = 100.0 - v * ts;
        t = ts + ss / a;
    }
    return t;
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
        double a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        double t1 = cal(a1,b1);
        double t2 = cal(a2,b2);
        // cout << t1 << " " << t2 << endl;
        if (abs(t1 - t2) <= 1e-6){
            cout << "Draw" << endl;
        }
        else if (t1 < t2){
            cout << "Megumin" << endl;
        }
        else if (t1 > t2){
            cout << "Yunyun" << endl;
        }
    }
    // cout << cal(3,7);
    return 0;
}
/*
v = s/t
t = s/v
*/