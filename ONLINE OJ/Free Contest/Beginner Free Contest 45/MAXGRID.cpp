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
    int n, m;
    cin >> n >> m;
    vector <int> listPos;
    vector <int> listNega;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int inp;
            cin >> inp;
            if (inp > 0){
                listPos.push_back(inp);
            }
            else{
                listNega.push_back(inp);
            }
        }
    }

    sort(listPos.rbegin(), listPos.rend());
    sort(listNega.begin(), listNega.end());


    for (int i = 0, j = 0; i < listNega.size() and j < listPos.size(); i++){
        cout << i << " " << j << endl;
        while(j < listPos.size() and abs(listNega[i]) <= listPos[j]){
            j++;
            cout << i << " " << j << endl;
        }
        if (j < listPos.size()){
            listNega[i] = -listNega[i];
            listPos[j] = -listPos[j];
            j++;
        }
    }

    int ans = 0;
    for (auto i: listNega){
        ans += i;
        cout << i << ' ';
    }
    cout << endl;
    for (auto i: listPos){
        ans += i;
        cout << i << " ";
    }
    cout << endl;
    

    cout << ans;
    return 0;
}