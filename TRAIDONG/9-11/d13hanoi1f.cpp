#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector <ii> sol;
int g[4][4];

void hanoi(int n, int a, int b){
    if (n >= 1){
        int c = 3 - a - b;
        if (g[a][b]){
            hanoi(n - 1, a, c);
            sol.push_back({a,b});
            hanoi(n - 1, c, b);
        }
        else{
            hanoi(n - 1,a,b);
            hanoi(1,a,c);
            hanoi(n - 1,b,a);
            hanoi(1,c,b);

            hanoi(n - 1,a,b);
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> g[i][j];
        }
    }

    hanoi(n,0,2);

    cout << sol.size() << endl;
    for (auto x: sol){
        // ii x = sol.back();
        // sol.pop_back();
        cout << char('A' + x.fi) << char('A' + x.se) << endl;
    }
    return 0;
}