#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[110];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> lists;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            int x;
            cin >> x;
            if (i != j){
                if (x == 1){
                    for (int k = i; k <= j; k++){
                        a[k] = 1;
                    }
                }
                else{
                    lists.push_back({i,j});
                }
            }
        }
    }
    for (int i = 1, cnt = 1; i <= n; i++){
        if (a[i] == 0){
            cnt++;
        }
        else if (a[i] == 1){
            a[i] = cnt;
        }
    }

    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    int checkSeg[110];
    memset(checkSeg,0,sizeof(checkSeg));
    for (int i = 1; i < lists.size(); i++){
        ii a = lists[i];
        for (int j = i - 1; j >= 0; j--){
            ii b = lists[j];
            if (a.fi <= b.fi and b.se <= a.se){
                checkSeg[j] = 1;
            }
        }
    }

    for (int i = 0; i < lists.size(); i++){
        if (checkSeg[i] == 0){
            
        }
    }
    return 0;
}