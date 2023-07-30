#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1000000 + 10;

vector <int> uoc[maxN];
int vis[maxN];

void init(){
    // int cnt = 0;
    for (int i = 2 ; i < maxN; i++){
        for (int j = i * 2; j < maxN; j += i){
            uoc[j].push_back(i);
        }
    }
}

signed main(){
    // freopen("divisors.INP", "r", stdin);
    // freopen("divisors.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int sa, te;
    cin >> sa >> te;
    for (int i = 1; i <= te; i++){
        vis[i] = 1e9;
    }
    vis[sa] = 0;
    for (int i = sa; i < te; i++){
        for (auto j: uoc[i]){
            if (i + j > te){
                break;
            }
            vis[i + j] = min(vis[i + j], vis[i] + 1);
        }
    }
    if (vis[te] == 1e9){
        cout << -1;
        return 0;
    }
    cout << vis[te];
    return 0;
}

/*
12970185
*/