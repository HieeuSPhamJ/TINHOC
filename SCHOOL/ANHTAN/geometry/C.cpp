#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int len(ii a){
    return a.fi * a.fi + a.se * a.se; 
}

void print(ii a, char en = endl){
    cout << a.fi << "," << a.se << en;
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
        ii v1, v2, v3;
        v1.fi = a.fi - b.fi;
        v1.se = a.se - b.se;
        v2.fi = a.fi - c.fi;
        v2.se = a.se - c.se;
        v3.fi = c.fi - b.fi;
        v3.se = c.se - b.se;
        // print(v1, ' ');
        // print(v2, ' ');
        // print(v3);
        
        int vuong = 0;
        int can = 0;
        if (v1.fi * v2.fi + v1.se * v2.se == 0){
            vuong = 1;
        }
        if (v3.fi * v2.fi + v3.se * v2.se == 0){
            vuong = 1;
        }
        if (v1.fi * v3.fi + v1.se * v3.se == 0){
            vuong = 1;
        }
        if (len(v1) == len(v2)){
            can = 1;
        }
        if (len(v1) == len(v3)){
            can = 1;
        }
        if (len(v3) == len(v2)){
            can = 1;
        }

        if (can and vuong){
            cout << 4 << endl;
        }
        else if (vuong){
            cout << 3 << endl;
        }
        else if (can){
            cout << 2 << endl;
        }
        else{
            cout << 1 << endl;
        }
    }
    return 0;
}