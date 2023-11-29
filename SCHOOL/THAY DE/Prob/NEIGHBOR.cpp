#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int n, k, a;
vector <int> ls;

int sub(int a, int b){
    return ((a - b) % n + n) % n;
}

int add(int a, int b){
    return (a + b) % n;
}

int old2new(int id){
    for (auto i: ls){
        cout << "With: " << i << endl;
        if (id == 0){
            id = i % n;
        }
        else{
            id = sub(id, i / n);
            cout << id << endl;
            if (id <= i % n){
                id = sub(id, 1);
            }
        }
        cout << id << endl;
    }
    return id;
}

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
    cin >> n >> k >> a;
    n--;
    a--;
    for (int i = 1; i <= k; i++){
        int x;
        cin >> x;
        ls.push_back(x);
    }

    cout << old2new(0);

    return 0;
}   