#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> nha;
    vector <int> khach;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        khach.push_back(inp);
    }
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        nha.push_back(inp);
    }
    sort(khach.begin(), khach.end());
    sort(nha.begin(), nha.end());

    // for (auto i: khach){
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto i: nha){
    //     cout << i << " ";
    // }
    // cout << endl;
    
    int ans = 0;
    while(!khach.empty() and !nha.empty()){
        if (khach.back() < nha.back()){
            khach.pop_back();
            nha.pop_back();
            ans++;
        }
        else{
            khach.pop_back();
        }
    }
    cout << ans;
    return 0;
}