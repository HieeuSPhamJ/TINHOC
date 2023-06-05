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
    int n, test;
    cin >> n >> test;
    vector <int> s;
    for (int i = 1; i <= n; i++){
        s.push_back(i);
    }
    while(test--){
        int a, b;
        cin >> a >> b;
        vector <int> temp;
        for (int i = 0; i < n; i++){
            if (s[i] != a){
                temp.push_back(s[i]);
                if (s[i] == b){
                    temp.push_back(a);
                }
            }
        }
        swap(temp,s);
    }
    int la = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == 1){
            la = i;
            break;
        }
    }
    for (int i = la, cnt = 1; cnt <= n; i++){
        i %= n;
        cnt++;
        cout << s[i] << " ";
    }
    return 0;
}