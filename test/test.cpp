#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

vector <int> a, b;
int n = 40;
int cnt = 0;

void backtrack(int id){
    if (id == 3){
        cnt++;
        return;
    }

    int s = 1;
    if (a.size()){
        s = a.back() + 1;
    }
    for (int i = s; i <= n; i++){
        // cout << "Add a: " << i << endl;
        a.push_back(i);
        backtrack(id + 1);
        a.pop_back();
    }
    s = 1;
    if (b.size()){
        s = b.back() + 1;
    }
    for (int i = s; i <= n; i++){
        // cout << "Add b: " << i << endl;
        b.push_back(i);
        backtrack(id + 1);
        b.pop_back();
    }
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
    for (int i = 1; i <= n; i++){
        backtrack(0);
    }
    cout << cnt << endl;
    return 0;
}