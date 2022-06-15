#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 10;

int moneyAdd[maxN];
int moneyPay[maxN];

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++){
        int x, a, b;
        cin >> x >> a >> b;
        if (x > 0){
            moneyAdd[b] += x;
        }
        else{
            moneyPay[a] += x;
        }

    }

    int check = 0;

    for (int i = 1; i <= m; i++){
        // cout << moneyAdd[i] << ' ' << moneyPay[i] << endl;
        s += moneyPay[i];
        if (s < 0){
            check = 1;
        }
        // cout << s << endl;
        s += moneyAdd[i];
    }

    if (check == 0){
        cout << "NO";
    }
    else{
        cout << "YES";
    }

    return 0;
}