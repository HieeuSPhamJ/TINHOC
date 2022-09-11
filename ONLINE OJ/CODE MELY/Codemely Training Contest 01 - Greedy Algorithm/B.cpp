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
        int n;
        cin >> n;
        int x;
        cin >> x;

        vector <int> a;
        vector <int> b;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            a.push_back(inp);
        }
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            b.push_back(inp);
        }

        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        int check = 0;

        for (int i = 0; i < n; i++){
            // cout << a[i] << " " << b[i] << endl;
            if (a[i] + b[i] > x){
                check = 1;
            }
        }
        if (check == 1){
            cout << "NO";
        }
        else{
            cout << "YES";
        }
        cout << endl;
    }
    return 0;
}