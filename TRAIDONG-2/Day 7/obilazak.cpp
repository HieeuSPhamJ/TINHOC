#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

vector <int> res[112];
int a[maxN];

void backtrack(int l, int r, int id){
    if (l == r){
        res[id].push_back(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    backtrack(l, mid - 1, id + 1);
    res[id].push_back(a[mid]);
    backtrack(mid + 1, r, id + 1);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("obilazak.inp", "r")) {
        freopen("obilazak.inp", "r", stdin);
        freopen("obilazak.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= (1 << n); i++){
        cin >> a[i];
    }
    backtrack(1,(1 << n) - 1,1);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < (int)res[i].size(); j++){
            cout << res[i][j];
            if (j != (int)res[i].size() - 1){
                cout << " ";
            }
        }
        if (i != n){
            cout << endl;
        }
    }
    return 0;
}