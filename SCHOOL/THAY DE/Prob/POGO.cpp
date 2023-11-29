#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int d[3][6];

int ans[100010][7];

struct dice{
    int data[6];

    void Try(int t){
        int temp[6];
        for (int i = 0; i < 6; i++){
            temp[i] = data[i];
        }
        for (int i = 0; i < 6; i++){
            data[i] = temp[d[t][i]];
        }
    }
    void print(){
        cout << "[";
        for (int i = 0; i < 6; i++){
            cout << data[i] << ",";
        }
        cout << "]";
        cout << endl;
    }
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // d[0] = {3,1,0,5,4,2};
    // d[1] = {2,1,5,0,4,3};
    // d[2] = {4,0,2,3,5,1};

    d[0][0] = 3;
    d[0][1] = 1;
    d[0][2] = 0;
    d[0][3] = 5;
    d[0][4] = 4;
    d[0][5] = 2;
    
    d[1][0] = 2;
    d[1][1] = 1;
    d[1][2] = 5;
    d[1][3] = 0;
    d[1][4] = 4;
    d[1][5] = 3;

    d[2][0] = 4;
    d[2][1] = 0;
    d[2][2] = 2;
    d[2][3] = 3;
    d[2][4] = 5;
    d[2][5] = 1;

    int n, m;
    cin >> n >> m;
    dice a;
    for (int i = 0; i < 6; i++){
        a.data[i] = i;
    }
    for (int i = 1; i <= 5; i++){
        if (i % 2){
            for (int j = 1; j <= m; j++){
                ans[i][j] = a.data[0];
                a.Try(0);
            }
            a.Try(1);
        }
        else{
            for (int j = m; j >= 1; j--){
                ans[i][j] = a.data[0];
                a.Try(1);
            }
            a.Try(0);
        }
        a.Try(2);
    }
    int sum[6];

    for (int i = 1; i <= 5; i++){
        sum[i - 1] = 0;
        for (int j = 1; j <= m; j++){
            sum[i - 1] += ans[i][j] + 1;
            // cout << ans[i][j] + 1 << " ";
        }
        // cout << endl;
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += sum[i % 4];
    }

    cout << ans << endl;

    return 0;
}