#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

struct dt{
    ii xy;
    int r, v;
};

struct line{
    int a, b, c;

    int cal(ii x){
        return a * x.fi + b * x.se + c;
    }
};

const int maxN = 20010;

dt a[maxN];
ii b[maxN];

double calLen(line d, ii x){
    return 1.0 * abs(d.cal(x)) / sqrt(d.a * d.a + d.b * d.b);
}

double lenPP(ii x, ii y){
    return sqrt((x.fi - y.fi) * (x.fi - y.fi) + (x.se - y.se) * (x.se - y.se));
}

double checkin(double a, double b, double c){
    // cout << "In: " << a << " " << b << " " << c << " " << (a * a + b * b - c * c) << endl;
    // if ((a * a + b * b - c * c) >= 0){
    //     return 1;
    // }
    return (a * a + b * b - c * c) / (2 * a * b);
    return 0;
}


signed main(){
    //freopen("concor.INP", "r", stdin);
    //freopen("concor.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n, d;
    cin >> m >> n >> d;

    for (int i = 1; i <= m; i++){
        cin >> a[i].xy.fi >> a[i].xy.se >> a[i].r >> a[i].v;
        a[i].r += d;
    }

    set <int> s;

    for (int i = 1; i <= n; i++){
        cin >> b[i].fi >> b[i].se;
    }
    b[0] = {0,0};
    b[n + 1] = b[0];
    for (int i = 0; i <= n; i++){
        ii u = b[i];
        ii v = b[i + 1];
        ii pt = {u.fi - v.fi, v.se - u.se};
        line tline;
        tline.a = pt.se;
        tline.b = pt.fi;
        tline.c = - (pt.se * u.fi + pt.fi * u.se);
        
        // cout << "With: " << tline.a << " " << tline.b << " " <<  tline.c << endl;

        double t = lenPP(u,v);
        for (int j = 1; j <= m; j++){
            double t1 = lenPP(a[j].xy,u);
            double t2 = lenPP(a[j].xy,v);
            double lenline = calLen(tline,a[j].xy);

            if (lenline <= a[j].r){
                // cout << "#" << i << " " << j << " ";
                // cout << checkin(t,t1,t2) << " " << checkin(t,t2,t1) << endl;
                // cout << t << " " << t1 << " " << t2 << endl;
                if ((min(t1,t2) <= a[j].r) or (checkin(t,t1,t2) >= 0 and checkin(t,t2,t1) >= 0) or (checkin(t,t1,t2) == 0.0 or checkin(t,t2,t1) == 0.0 or checkin(t,t1,t2) == -1.0 or checkin(t,t2,t1) == -1.0)){
                    if (s.find(j) == s.end()){
                        // cout << i << " " << a[j].v << " " << lenline << endl;
                    }
                    s.insert(j);
                }
            }
        }
    }

    int ans = 0;

    for (auto i: s){
        ans += a[i].v;
    }
    
    cout << ans << endl;

    return 0;
}