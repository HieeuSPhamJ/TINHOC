#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int d[20][20];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        for (int j = i + 1; j <= n; j++){
            cin >> d[i - 1][j - 1];
        }
    }
    int res = 0;

    for (int mask = 0; mask < (1 << n); mask++){
        vector <int> ls;
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                ls.push_back(i);
            }
        }
        if (ls.size() % 2){
            continue;
        }
        int tres = 0;
        for (int i = 1; i < ls.size(); i += 2){
            tres += d[i - 1][i];
        }
        cout << tres << ": " << endl;
        for (auto i: ls){
            cout << i + 1 << " ";
        }
        cout << endl;
        res = max(res,tres);
    }   

    cout << res << endl;
    return 0;
}