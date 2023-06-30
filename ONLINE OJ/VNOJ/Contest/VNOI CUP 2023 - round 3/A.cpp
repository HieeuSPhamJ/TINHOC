#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

bool cal(vector <int> ls, int a, int b){
    int l = ls.back();
    while(ls.size() and ls.back() + a >= l){
        ls.pop_back();
    }
    l = ls.back();
    // cout << ls.size() << endl;
    while(ls.size() and ls.back() + b >= l){
        ls.pop_back();
    }
    // cout << ls.size() << endl;
    return !ls.size();
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, a, b;
        cin >> n >> a >> b;
        vector <int> ls;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            ls.push_back(x);
        }
        
        if (cal(ls, a, b) or cal(ls, b, a)){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}