#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int c;
int a[maxN];
vector <int> temp;
vector <int> melody;

signed main(){
    freopen("MOOSICK.INP", "r", stdin);
    freopen("MOOSICK.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> c;

    for (int i = 1; i <= c; i++){
        int inp;
        cin >> inp;
        melody.push_back(inp);
    }
    sort(melody.begin(), melody.end());
    vector <int> ans;
    for (int i = c; i <= n; i++){
        temp.clear();
        for (int j = i; j >= i - c + 1; j--){
            temp.push_back(a[j]);
        }
        // for (auto x: temp){
        //     cout << x << " ";
        // }
        // cout << endl;
        sort(temp.begin(), temp.end());
        int del = temp[0] - melody[0];
        int check = 1;
        for (int j = 0; j < c; j++){
            if (del != temp[j] - melody[j]){
                check = 0;
            }
        }
        if (check){
            ans.push_back(i - c + 1);
        }
    }
    cout << ans.size() << endl;
    for (auto i: ans){
        cout << i << endl;
    }
    return 0;
}