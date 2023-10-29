#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int hang[60];
int cot[60];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("square.inp", "r")) {
        freopen("square.inp", "r", stdin);
        freopen("square.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        memset(hang,0,sizeof(hang));
        memset(cot,0,sizeof(cot));
        
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                char x;
                cin >> x;
                if (x == 'X'){
                    hang[i]++;
                    cot[i]++;
                }
            }
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 1; i <= n; i++){
            if (hang[i] == 1){
                cnt1++;
            }
            if (hang[i] == 2){
                cnt2++;
            }
        }
        if (!(cnt1 == 1 and cnt2 == n - 1)){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 1; i <= n; i++){
            if (cot[i] == 1){
                cnt1++;
            }
            if (cot[i] == 2){
                cnt2++;
            }
        }

        if (!(cnt1 == 1 and cnt2 == n - 1)){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        cout << "POSSIBLE" << endl;
    }
    return 0;
}

/*
...xx
.xx..
x....
.xx..
..x.x
*/