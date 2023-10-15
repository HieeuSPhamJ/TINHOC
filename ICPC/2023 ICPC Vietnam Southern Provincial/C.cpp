#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

vector <int> ls[4];
map <int,int> cv[4];

void nenso(int t){
    set <int> s;
    for (auto i: ls[t]){
        s.insert(t);
    }
    int cnt = 1;
    for (auto i: s){
        cv[t][i] = cnt;
        cnt++;
    }
}

int a[1010][1010];
int pre[4][1010];
int sto[1010][1010];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector <ii> lsx, lsy, lsz;
    for (int i = 1; i <= k; i++){
        int x, y, z;
        cin >> x >> y >> z;
        ls[0].push_back(x);
        ls[1].push_back(y);
        ls[2].push_back(z);
        if (x == 1){
            lsx.push_back({y,z});
        }
        if (y == 1){
            lsy.push_back({x,z});
        }
        if (z == 1){
            lsz.push_back({x,y});
        }
    }
    nenso(0);
    nenso(1);
    nenso(2);

    for (auto &i: lsx){
        i.fi = cv[1][i.fi];
        i.se = cv[2][i.se];
    }
    for (auto &i: lsy){
        i.fi = cv[0][i.fi];
        i.se = cv[2][i.se];
    }
    for (auto &i: lsz){
        i.fi = cv[0][i.fi];
        i.se = cv[1][i.se];
    }
    int res = 0;
    for (auto i: lsz){
        if (a[i.fi][i.se] == 0){
            res += n;
            pre[0][i.fi]++;
            pre[1][i.se]++;
        }
        a[i.fi][i.se] = 1;
    }
    for (auto i: lsy){
        res += n;
        pre[3][i.se]++;
        res -= pre[0][i.fi];
    }

    for (auto i: lsx){
        res += n;
        res -= pre[1][i.fi];
        res -= pre[2][i.se];
        res += sto[i.fi][i.se];
    }

        
    return 0;
}