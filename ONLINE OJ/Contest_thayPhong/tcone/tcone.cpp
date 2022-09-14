#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set <int> lists;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        lists.insert(inp);
    }

    vector <int> a;

    for (auto i: lists){
        a.push_back(i);
    }

    int ans = 0;

    int check = 1;
    for (int i = 2; i < a.size(); i++){
        if (a[i] % a[0] != 0){
            check = 0;
        }
    }
    if (check == 1){
        ans= a[0];
    }

    check = 1;
    for (int i = 2; i < a.size(); i++){
        if (a[i] % a[1] != 0){
            check = 0;
        }
    }
    if (check == 1){
        ans = a[1];
    }

    cout << ans;

    return 0;
}