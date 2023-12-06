#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2e5 + 10;


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("tour.inp", "r")) {
        freopen("tour.inp", "r", stdin);
        freopen("tour.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    vector <pair<int,ii>> query;
    for (int i = 1; i <= test; i++){
        char c;
        cin >> c;
        int a, b;
        cin >> a >> b;
        if (c == 'A'){
            query.push_back({0,{a,b}});
        }
        else if (c == 'B'){
            query.push_back({1,{a,b}});
        }
        else{
            query.push_back({2,{a,b}});
        }
    }
    
    return 0;
}