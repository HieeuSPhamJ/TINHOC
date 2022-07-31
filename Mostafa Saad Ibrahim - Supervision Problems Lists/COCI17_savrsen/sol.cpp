#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 1e7 + 10;

int divSum[maxN + 1];
// vector <int> listDiv[maxN + 1];

void Eras(){
    for (int i = 2; i < maxN; i++){
        divSum[i] += 1;
        // listDiv[i].push_back(1);
    }
    for (int i = 2; i <= maxN; i++){
        for (int j = 2; i * j <= maxN; j++){
            divSum[i * j] += i;
            // listDiv[i * j].push_back(i);
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Eras();
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++){
        // cout << divSum[i] << ' ';
        ans += abs(i - divSum[i]);
    }

    // for (int i = 1; i <= 100; i++){
    //     cout << i << ": " << abs(i - divSum[i]) << " " << divSum[i] << endl;
    //     for (auto j: listDiv[i]){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans;
    return 0;
}