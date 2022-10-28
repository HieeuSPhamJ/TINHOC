#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <int,ii>
#define dii pair <double,ii>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const double eps = 0.00000001;

vector <iii> points;
vector <dii> E;
int root[1000000];

int findRoot(int n){
    if (n == root[n]){
        return n;
    }
    return root[n] = findRoot(root[n]);
}

double callen(ii a, ii b){
    double x = a.fi - b.fi;
    double y = a.se - b.se;
    // cout << x << " " << y << endl;
    return sqrtl(x * x + y * y);
}

signed main(){
    freopen("Conect.INP", "r", stdin);
    freopen("Conect.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        points.push_back({i,{a,b}});
        root[i] = i;
    }
    for (auto i: points){   
    for (auto j: points){
        if (i.fi == j.fi){
            continue;
        }
        double r = callen(i.se, j.se);
        E.push_back({r, {i.fi, j.fi}});
    }
    }

    sort(E.rbegin(), E.rend());

    // for (auto i: E){
    //     cout << i.fi << " " << i.se.fi << " " << i.se.se << endl;
    // }

    int com = n;
    double r = 0;
    while(com > 1){
        dii e = E.back();
        E.pop_back();
        int a = findRoot(e.se.fi);
        int b = findRoot(e.se.se);

        if (a == b){
            continue;
        }
        // cout << e.fi << " " << e.se.fi << " " << e.se.se << endl;
        r = e.fi / 2.0;
        com--;
        root[a] = b;
    }
    r += eps;
    int x = (r * 1e7);
    int d = x % (int)(1e7);
    x = x / (int)(1e7);
    
    if (d == 0){
        cout << x << "." << "0000000" << endl;
        return 0;
    }
    while(d < (int)(1e7)){
        d *= 10;
    }
    cout << x << "." << d << endl;
    // cout << fixed << setprecision(7) << r;
    
    return 0;
}