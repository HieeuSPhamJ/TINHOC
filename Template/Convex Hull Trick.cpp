#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;


struct line{
    int a, b;
    line(int _a,int _b){
        a = _a;
        b = _b;
    }
    int val(int x){
        return a * x + b;
    }
};
 
bool check(line x1, line x2, line x3){
    return (double) (x1.b - x3.b) / (x3.a - x1.a) <= (double) (x2.b - x3.b) / (x3.a - x2.a);
}
bool sus(line d1,line d2,line d3){
    return  (double)(d3.b - d1.b) / (d1.a - d3.a) <= (double)(d2.b - d1.b) / (d1.a - d2.a);
}
struct CHT{
    vector <line> ls;
    void add(line x){
        while(ls.size() >= 2 and sus(ls[ls.size() - 2], ls.back(), x)){
            ls.pop_back();
        }
        ls.push_back(x);
    }
    int query(int x){
        int res = 1e18;
        int l = 0;
        int r = ls.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            int t = ls[mid].val(x);
            res = min(res,t);
            if (mid != ls.size() - 1 and t > ls[mid + 1].val(x)){
                l = mid + 1;
            }
            else if (mid != 0 and t > ls[mid - 1].val(x)){
                r = mid - 1;
            }
            else{
                return res;
            }
        }
        return res;
    }
};

const int maxN = 1e5 + 10;
 
int a[maxN];
int b[maxN];
int dp[maxN];
 
 
signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    CHT cht;
    cht.add(line(b[1], 0));
    for (int i = 1; i <= n; i++){
        int dp = cht.query(a[i]);
        cht.add(line(b[i], dp));
    }
    cout << cht.query(a[n]);
    return 0;
}