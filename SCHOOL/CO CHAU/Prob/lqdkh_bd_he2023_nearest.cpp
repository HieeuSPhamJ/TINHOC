#include<bits/stdc++.h>
#define ii pair <int,int>
#define dd pair <double,double>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;
 
vector <dd> ls;
 
double cal(dd a, dd b){
    return ((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}
 
void print(dd a, char en = endl){
    cout << "[" << a.fi << "," << a.se << "]" << en;
}
 
signed main(){
    freopen("nearest.INP", "r", stdin);
    freopen("nearest.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        double x, y;
        cin >> x >> y;
        ls.push_back({x,y});
    }
    sort(all(ls));
    set <dd> s;
    double res = 1e18;
    for (auto i: ls){
        double d = ceil(sqrt(res));
        // cout << "With: ";
        // print(i);
        set <dd> t;
        while(1){
            auto it = s.lower_bound({i.se - d, 0});
            if (it == s.end()){
                break;
            }
            dd j = {(*it).se, (*it).fi};
            if (j.fi < i.fi - d){
                s.erase(it);
                continue;
            }
            t.insert(*it);
            s.erase(it);
            res = min(res, cal(i,j));
        }
 
        for (auto x: t){
            s.insert(x);
        }
 
        s.insert({i.se,i.fi});
    }
 
    cout << fixed << setprecision(3) << sqrt(res) << endl;
 
    return 0;
}