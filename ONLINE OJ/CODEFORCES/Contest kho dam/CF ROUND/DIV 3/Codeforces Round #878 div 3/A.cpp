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
        vector <char> s;
        while(n--){
            char c;
            cin >> c;
            if (s.size() and s.front() == c){
                cout << c;
                s.clear();
            }
            else{
                s.push_back(c);
            }
        }
        cout << endl;
    }
    return 0;
}