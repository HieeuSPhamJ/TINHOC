#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
        set <int> s;
        vector <int> ls;
        int nega = 0;
        while(n--){
            int x;
            cin >> x;
            if (x < 0){
                nega++;
            }
            ls.push_back(x);
        }
        sort(rall(ls));
        for (auto x: ls){
            x = abs(x);
            if (s.find(x) != s.end()){
                s.erase(s.find(x));
            }
            else{
                s.insert(x);
            }
            cout << s.size() << " ";
            // cout << endl;
        }
        cout << endl;

        for (int i = 1; i <= nega * 2; i++){
            if (i % 2){
                cout << 1 << " ";
            }
            else{
                cout << 0 << " ";
            }
        }
        for (int i = 1; i <= ls.size() - nega * 2; i++){
            cout << i << " ";
        }
        cout << endl;


    }
    return 0;
}