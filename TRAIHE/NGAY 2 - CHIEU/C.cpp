#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define int long long
#define s second
using namespace std;



signed main(){
    freopen("divexp.inp", "r", stdin);
    freopen("divexp.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, k;
    cin >> a >> b >> k;
    a--;

    int ansA = 0;
    int ansB = 0;

    // cout << 12 / power(2, 10);

    for (int i = 2; i <= a; i++){
        int po = 1;
        int check = 0;
        for (int j = 1; j <= k; j++){
            po *= i;
            if (po > a){
                check = 1;
            }
        }
        if (check == 1){
            ansA += (a / i);
            continue;
        }
        ansA += ((a / i) - (a / po));
        // cout << ansA << endl;
    }


    for (int i = 2; i <= b; i++){
        int po = 1;
        int check = 0;
        for (int j = 1; j <= k; j++){
            po *= i;
            if (po > b){
                check = 1;
            }
        }
        if (check == 1){
            ansB += (b / i);
            continue;
        }
        ansB += ((b / i) - (b / po));
        // cout << ansB << endl;
    }
    // cout << ansB << " " << ansA << endl;
    cout << ansB - ansA;

    

    return 0;
}