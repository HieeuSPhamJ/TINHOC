#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct cirl{
    int w, r;
};

int n, m, q, k;

int a[510][510];
int conv[510][510];
ii reconv[100];
vector <cirl> lists[100];
int prefix[510][510];

bool cmp(cirl x, cirl y){
    return x.r > y.r;   
}

void print(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void reset(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            prefix[i][j] = 0;
        }
    }
}

void sol(int type){
    ii I = reconv[type];
    // cout << "TYPE: " << type << " : " << I.fi << " " << I.se << endl;
    while (!lists[type].empty()){
        int R = lists[type].back().r;
        int W = 0;
        // cout << "Lists Cir: " << R << endl;
        while(!lists[type].empty() and lists[type].back().r == R){
            // cout << lists[type].back().w << " " << lists[type].back().r << endl;
            W += lists[type].back().w;
            lists[type].pop_back();
        }
        if (W == 0){
            // cout << "W == 0" << endl;
            continue;
        }
        if (R == 0){
            prefix[I.fi][I.se] += W;
            prefix[I.fi + 1][I.se] -= W;
            // cout << "R == 0" << endl;
            continue;
        }
        // cout << "---" << endl;
        // reset();
        // print();
        for (int x = max(1ll, I.fi - R); x <= min(n, I.fi + R); x++){
            int left = -R + abs(x - I.fi) + I.se;
            int right = R - abs(x - I.fi) + I.se;
            prefix[x][max(left, 1ll)] += W;
            prefix[x][right + 1] -= W;
            // cout << "[" << x << "," << max(left, 1ll) << "] ";
            // cout << "[" << x << "," << right << "] " << endl;
        }
        // print();
    }
}

/*
|x - u| + |y - v| = R
|x - u| = R - |y - v|
+1: x = -R + |y - v| - u
-1: x = R - |y - v| + u

*/

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> q >> k;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        conv[x][y] = i;
        reconv[i] = {x,y};
    }


    for (int i = 1; i <= k; i++){
        int w, r1, r2, x, y;
        cin >> w >> r1 >> r2 >> x >> y;
        lists[conv[x][y]].push_back({w,r1});
        lists[conv[x][y]].push_back({-w,r2});
    }

    for (int i = 1; i <= q; i++){
        sort(lists[i].begin(), lists[i].end(),cmp);
    }

    for (int i = 1; i <= q; i++){
        sol(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        int temp = 0;
        for (int j = 1; j <= m; j++){
            temp += prefix[i][j];
            ans += min(temp, a[i][j]);
            // cout << temp << " ";
        }
        // cout << endl;
    }

    cout << ans;

    return 0;
}