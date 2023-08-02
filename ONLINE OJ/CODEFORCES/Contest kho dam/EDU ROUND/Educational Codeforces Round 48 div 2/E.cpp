#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int n;
ii a[maxN];
int p[maxN];

double len(ii x, ii y){
    return sqrt((x.fi - y.fi) * (x.fi - y.fi) + (x.se - y.se) * (x.se - y.se));
}

double calx(int x, int y, int A, int s){
    if (x == A){
        return x;
    }
    double res = (- (s - y)) * x + (A - x) * y;
    res /= (- (s - y));
    return res;
}

double cal(double x){
    int l = 1;
    int r = n + 1;
    int res = 0;
    while(l <= r){
        int i = (l + r) / 2;
        if (a[i].fi <= x and x <= a[i].se){
            return p[i - 1] + (x - a[i].fi);
        }
        if (a[i - 1].se <= x and x <= a[i].fi){
            return p[i - 1];
        }
        if (a[i].se < x){
            l = i + 1;
        }
        else{
            r = i - 1;
        }
        
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s, A, B;
    cin >> s >> A >> B;
    int base = B - A;
    
    cin >> n;
    a[0] = {0,0};
    a[n + 1] = {1e17, 1e18};
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        p[i] = p[i - 1] + a[i].se - a[i].fi;
    }
    int test;
    cin >> test;
    while(test--){
        int x, y;
        cin >> x >> y;
        double k = 1.0 * (y - s) / y;
        
        double l = calx(x,y,A,s);
        double r = calx(x,y,B,s);
        // cout << l << " " << r << endl;
        double cover = cal(r) - cal(l);
        // cout << cover << " " << (y - s) << endl;
        cout << fixed << setprecision(15) << cover * k << endl;
    }

    // cout << cal(3,1,1,-3);
    return 0;
}

/*
123456789012345
000000000000000
*/