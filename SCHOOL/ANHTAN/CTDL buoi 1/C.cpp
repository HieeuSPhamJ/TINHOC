#include<bits/stdc++.h>
using namespace std;

struct where{
    int loc = 0;
    int ants = 0;
};

const int maxN = 1e6 + 10;

where a[maxN];
long long leftVal[maxN];
long long rightVal[maxN];

bool cmp(where a, where b){
    return a.loc < b.loc;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].ants;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i].loc;
    }
    sort(a + 1, a + 1 + n, cmp);
    a[n + 1].loc = a[n].loc + 1;

    long long totalAnt = 0;

    for (int i = 1; i <= n; i++){
        leftVal[i] = leftVal[i - 1] + totalAnt * (a[i].loc - a[i - 1].loc);
        totalAnt += a[i].ants;
    }

    totalAnt = 0;
    for (int i = n; i >= 1; i--){
        rightVal[i] = rightVal[i + 1] + totalAnt * abs(a[i].loc - a[i + 1].loc);
        totalAnt += a[i].ants;
    }
    // for (int i = 1; i <= n; i++){
    //     cout << leftVal[i] << ' ';
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << rightVal[i] << ' ';
    // }
    // cout << endl;

    long long ans = 1e18;
    for (int i = 1; i <= n; i++){
        ans = min(ans, leftVal[i] + rightVal[i]);
    }
    cout << ans;

    return 0;
}