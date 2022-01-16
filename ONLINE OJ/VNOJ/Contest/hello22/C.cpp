#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e7;

bool check[maxN]={false};

void setup(int n){
    check[1] = 1;
    for (int i = 2; i * i <= n; i++){
        if (check[i] == 0){
            for (int e = 2;e * i <= n; e++){
                check[i * e] = 1;
            }
        }
    }
    // for (int i = 1; i <= n; i++){
    //     if (!check[i])
    //     cout << i << ": " << !check[i] << endl;
    // }
}

int main(){
    int n, m;
    cin >> n >> m;
    setup(1e7);
    long long ans = 0;
    for (int i = 1; i <= max(n, m); i++){
        if (check[i + 1] == 0 and i != max(m, n)){
            ans += min(min(n, m), i);
            // cout << i << ' ' << min(min(n, m), i) << endl;
        }
    }

    // cout << ans << endl;

    for (int i = max(n, m); i <= n + m; i++){
        if (check[i + 1] == 0){
            int tempI = i - max(n, m) + 1;
            ans += min(n, m) - tempI + 1;
            // cout << tempI << ' ' << min(n, m) - tempI + 1 << endl;
        }
    }
    cout << ans;
    return 0;
}