#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2000;

int n, m, dayk;
int vis[maxN];

vector <int> power(vector <int> ls, int k){
    if (k == 1){
        return ls;
    }
    vector <int> t = power(ls, / 2);
    vector <int> tt;
    for (auto i: t){    
        for (int j: t){

        }
    } 
}

signed main(){
    // freopen("flu.INP", "r", stdin);
    // freopen("flu.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> dayk >> m >> n;
    vector <int> ls.;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ls.push_back(x);
    }
    ls = power(ls,k);
    return 0;
}

/*
1 2 3
1 2 3 4 6 9
1 2 3 4 6 9
*/