#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
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
        vector <int> a;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            int l = a.size() - 1;
            if (a.size() <= 1){
                a.push_back(x);
                // cout << "take: " << i << endl;
            }
            else{
                if ((a[l - 1] - a[l]) * (a[l] - x) >= 0){
                    a.pop_back();
                    a.push_back(x);
                    // cout << "pop: " << i << endl;
                }
                else{
                    a.push_back(x);
                }
            }
        }
        if (a.size() == 2 and a[0] - a[1] == 0){
            cout << 1 << endl;
            continue;
        }
        cout << a.size() << endl;
    }
    return 0;
}

/*
5 4 2 1 0 0 4
5 0
*/