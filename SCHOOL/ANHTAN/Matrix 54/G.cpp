#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define iii pair <ii,int>
#define endl '\n'
using namespace std;

int mod = 1e9 + 7;

struct matrix {
    int R, C; 
    vector <vector <long long> > data;
    matrix(int _R, int _C) {
        R = _R; 
        C = _C; 
        data.resize(R); 
        for (int i = 0; i < R; i++) {
        data[i].resize(C, 0); 
        }
    }
    matrix operator *(const matrix &other) {
        matrix ret(R, other.C);
        for (int i = 0; i < R; i++) {
        for (int j = 0; j < other.C; j++) {
            long long sum = 0; 
            for (int k = 0; k < C; k++) {
            sum = (sum + (data[i][k] * other.data[k][j]) % mod) % mod; 
            }
            ret.data[i][j] = sum; 
        }
        }
        return ret;  
    }
};



matrix power(const matrix &M, int n) {
    if (n == 1) {
        return M; 
    }
    else {
        matrix ret = power(M, n / 2); 
        ret = ret * ret; 
        if (n % 2 == 1) {
        ret = ret * M; 
        }
        return ret; 
    }
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[8][8] = {
        {0,1,0,1,1,0,0,0},
        {1,0,1,0,0,1,0,0},
        {0,1,0,1,0,0,1,0},
        {1,0,1,0,0,0,0,1},
        {1,0,0,0,0,1,0,1},
        {0,1,0,0,1,0,1,0},
        {0,0,1,0,0,1,0,1},
        {0,0,0,1,1,0,1,0}
    };

    matrix base(24,24);
    set <ii> listsSet;
    map <ii,int> conv;
    int cnt = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (a[i][j]){
                listsSet.insert({i,j});
            }
        }
    }
    vector <ii> lists;
    for (auto i: listsSet){
        lists.push_back(i);
        conv[i] = cnt;
        cnt++;
    }
    // cout << cnt << endl;
    for (auto i: lists){
        for (int x = 0; x < 8; x++){
            if (a[i.se][x] == 1 and x != i.fi){
                base.data[conv[i]][conv[{i.se,x}]] = 1;
            }
        }
    }

    char x, y;
    cin >> x >> y;
    int n;
    cin >> n >> mod;
    int A = x - 'A';
    int B = y - 'A';
    
    matrix BASE = power(base,n);
    int ans = 0;

    // for (int i = 0; i < 24; i++){
    //     for (int j = 0; j < 24; j++){
    //         // if (base.data[i][j]){
    //         //     // cout << lists[i].fi << " " << lists[i].se << " " << lists[j].fi << " " << lists[j].se << endl;
    //         //     // cout << (conv[lists[i]] == i) << " " << (conv[lists[j]] == j) << endl;
    //         // }
    //         cout << base.data[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < 24; i++){
        cout << i << ": " << lists[i].fi << " " << lists[i].se << endl;
    }

    // cout << BASE.data[conv[{1,2}]][conv[{2,6}]] << endl;

    // for (int i = 0; i < 8; i++){
    //     for (int j = 0; j < 8; j++){
    //         if (a[A][i] == 1 and a[j][B] == 1){
    //             if (BASE.data[conv[{A,i}]][conv[{j,B}]] == 0){
    //                 continue;
    //             }
    //             cout << A << " " << i << " " << j << " " << B << endl;
    //             // cout << conv[{A,i}] << " " << conv[{j,B}] << endl;
    //             ans += BASE.data[conv[{A,i}]][conv[{j,B}]];
    //             ans = ans % mod;
    //         }
    //     }
    // }


    cout << ans;

    return 0;
}