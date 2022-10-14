#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int n;
int a[maxN];
int check[maxN];
vector <ii> lists[34];
int checkBit[34];


bool getBit(int mask, int i){
    return (mask & (1 << i));
}

int onBit(int mask, int i){
    return mask | (1 << i);
}

int offBit(int mask, int i){
    return (mask xor (1 << i));
}

int countBits(int mask){
    int count = 0;
    while (mask){
        count += (mask & 1);
        mask >>= 1;
    }
    return count;
}


void init(){
    for (int i = 0; i < maxN; i++){
        a[i] = 0;
        check[i] = 0;
    }
    for (int i = 0; i < 34; i++){
        lists[i].clear();
        checkBit[i] = 0;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        // cout << "------" << endl;
        // cout << "TEST: " << endl;
        cin >> n;
        init();
        for (int i =1; i <= n; i++){
            cin >> a[i];
            for (int j = log2(a[i]); j >= 0; j--){
                if (getBit(a[i], j)){
                    lists[j].push_back({a[i], i});
                }
            }
        }   

        // for (int i = 0; i <= 5; i++){
        //     cout << "Bit " << i << ": ";
        //     for (auto x: lists[i]){
        //         cout << x.fi << "," << x.se << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        int mask = 0;
        for (int i = 33; i >= 0; i--){
            int tmask = mask;
            ii tans = {0,0};
            if (checkBit[i] == 1){
                continue;
            }
            // cout << "#" << i << endl;
            for (int j = 0; j < lists[i].size(); j++){
                if (check[lists[i][j].se] == 0 and tmask < (mask | lists[i][j].fi)){
                    // cout << lists[i][j].fi << " ";
                    tmask = (mask | lists[i][j].fi);
                    tans = lists[i][j];
                }
            }
            // cout << endl;
            if (tans.se == 0){
                continue;
            }
            for (int j = log2(tans.fi); j >= 0; j--){
                if (getBit(tans.fi, j)){
                    checkBit[j] = 1;
                }
            }
            check[tans.se] = 1;
            mask = tmask;
            cout << tans.fi << " ";
        }

        for (int i = 1; i <= n; i++){
            if (check[i] == 0){
                cout << a[i] << " ";
            }
        }

        cout << endl;
    }
    return 0;
}