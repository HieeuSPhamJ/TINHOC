#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        if (k % 2 == 0){
            vector <char> ls;
            for (int i = 1; i <= n; i++){
                char x;
                cin >> x;
                ls.push_back(x);
            }
            sort(all(ls));
            for (auto i: ls){
                cout << i;
            }
            cout << endl;
        }
        else{
            vector <char> ls[2];
            for (int i = 1; i <= n; i++){
                char x;
                cin >> x;
                ls[i % 2].push_back(x);
            }
            sort(all(ls[0]));
            sort(all(ls[1]));
            // for (auto i: ls[0]){
            //     cout << i;
            // }
            // cout << endl;
            for (int i = 0; i < n; i++){
                cout << ls[(i + 1) % 2][i / 2];
            }
            cout << endl;
        }
    }
    return 0;
}