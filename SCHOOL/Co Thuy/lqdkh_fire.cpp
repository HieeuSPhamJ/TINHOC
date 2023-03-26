#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 100 + 10;

struct type(){
    int time, burn, cost;
} a[maxM];

bool cmp(type a, type b){
    return a.burn < b.burn;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].time >> a[i].burn >> a[i].cost;
    }
    sort(a + 1, a + 1 + n, cmp);

    

    return 0;
}