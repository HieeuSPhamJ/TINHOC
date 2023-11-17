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
vector <int> ls[maxN];

signed main(){
    freopen("permutation.INP", "r", stdin);
    freopen("permutation.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ls[a[i]].push_back(i);
    }

    for (int i = 1; i <= 1e5; i++){
        if (ls[i].size() < ls[i + 1].size()){
            cout << -1 << endl;
            return 0;
        }
        // cout << i << ": ";
        while(ls[i].size()){
            // cout << ls[i].back() << " ";
            a[ls[i].back()] = ls[i].size();
            ls[i].pop_back();
        }
        // cout << endl;
    }
    cout << *max_element(a + 1, a + 1 + n) << endl;
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}