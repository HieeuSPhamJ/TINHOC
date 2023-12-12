#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define dd pair <double,double>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2010;

int n, s, d;
bool mk[maxN];
pair<dd,double> ra[maxN];
int cost[maxN];

void print(dd x, char en = endl){
    cout << "(" << x.fi << "," << x.se << ")" << en;
}

double dist(double a, double b, double c, dd x){
    return abs(a * x.fi + b * x.se + c) / sqrt(a * a + b * b);
}

int sc(dd a, dd b, dd c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se);
}

double dist(dd a, dd b){
    return sqrt(1.0 * (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}

bool check(double a, double b, double c){
    // cout << a << " " << b << " " << c << endl;
    return (a * a + b * b - c * c) / 2 * a * b < 0;
}

bool checktu(double a, double b, double c){
    return check(a,b,c) or check(a,c,b);
}

void adu(dd x, dd y){
    // cout << "==!==" << endl;
    int a = x.fi - y.fi;
    int b = x.se - y.se;
    swap(a,b);
    a = -a;
    int c = -(a * x.fi + b * x.se); 
    // print(x, ' ');
    // print(y);
    // cout << a << " " << b << " " << c << endl;
    for (int i = 1; i <= n; i++){
        // print(ra[i].fi, ':');
        // cout << " " << ra[i].se << endl;
        if (dist(x,ra[i].fi) <= ra[i].se or dist(y, ra[i].fi) <= ra[i].se){
            mk[i] = 1;
            // cout << "#1" << endl;
        }
        else if (!checktu(dist(x,y), dist(ra[i].fi, x), dist(ra[i].fi, y)) and dist(a,b,c,ra[i].fi) <= ra[i].se){
            mk[i] = 1;
            // cout << "#2" << endl;
        }
    }
}

/*
v.fi * x.fi + v.se * x.se + c == 0

*/

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s >> d;
    for (int i = 1; i <= n; i++){
        cin >> ra[i].fi.fi >> ra[i].fi.se >> ra[i].se >> cost[i]; 
        ra[i].se += d;
    }
    vector <dd> ls;
    ls.push_back({0,0});
    for (int i = 1; i <= s; i++){
        int x, y;
        cin >> x >> y;
        ls.push_back({x,y});
    }
    ls.push_back({0,0});
    
    for (int i = 0; i < ls.size() - 1; i++){
        adu(ls[i], ls[i + 1]);
    }

    int res = 0;
    
    for (int i = 1; i <= n; i++){
        if (mk[i]){
            res += cost[i];
        }
    }

    cout << res << endl;
    return 0;
}