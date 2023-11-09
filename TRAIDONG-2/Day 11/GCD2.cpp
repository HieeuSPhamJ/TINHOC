#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int mk[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> ls;
    for (int i = n; i > 1; i--){
        if (mk[i]){
            continue;
        }
        cout << i << ": ";
        ls.push_back(i);
        for (int j = 2; j <= i; j++){
            if (__gcd(i,j) == j){
                mk[j] = i;
                cout << j << " ";
            }
        }
        cout << endl;
    }
    cout << (int)ls.size() - 1 << endl;
    fflush(stdout);
    int t;

    for (auto i: ls){
        cout << "? " << i << endl;
        fflush(stdout);
        cin >> t;
        if (t != 1){
            cout << "! " << t << endl;
            fflush(stdout);
            return 0;
        }
    }
    cout << "! " << t << endl;
    fflush(stdout);
    return 0;
}

/*
1 2 3 4 5 6
2 3 4 6
5
1
*/