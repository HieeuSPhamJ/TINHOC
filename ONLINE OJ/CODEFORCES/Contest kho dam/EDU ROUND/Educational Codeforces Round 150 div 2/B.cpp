#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

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
        int ok = 0;
        vector <int> ls;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if (ls.empty()){
                ls.push_back(x);
                cout << 1;
                continue;
            }

            if (ok){
                if (ls.back() > x){
                    // cout << ".";
                    cout << 0;
                    continue;
                }
                if (ls.back() <= x and x > ls[0]){
                    // cout << '#';
                    cout << 0;
                    continue;
                }
            }
            else{
                if (ls.back() > x){
                    if (x <= ls[0]){
                        ok = 1;
                        // cout << ",";
                        ls.push_back(x);
                        cout << 1;
                        continue;
                    }
                    else{
                        // cout << "!";
                        cout << 0;
                        continue;
                    }
                }
            }
            
            ls.push_back(x);
            cout << 1;
        }
        cout << endl;
    }
    return 0;
}

/*
3 7 7 9 2 4 6 3 4

1 1 1 1 1 0 0 1 0
1 1 1 1,1#0#0.0#0

*/