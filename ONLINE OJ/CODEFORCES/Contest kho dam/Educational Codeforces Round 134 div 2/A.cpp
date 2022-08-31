#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        set <char> S;
        for (int i = 1; i <= 2; i++){
            for (int j = 1; j <= 2; j++){
                char inp;
                cin >> inp;
                S.insert(inp);
            }
        }
        cout << S.size() - 1 << endl;
    }
    return 0;
}