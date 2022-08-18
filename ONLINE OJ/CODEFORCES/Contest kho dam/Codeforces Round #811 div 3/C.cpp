#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5;
int a[maxN];
map <int,int> countNum;

void printA(){
    for (int i = 1; i <= 5; i++){
        cout << i << ":" << countNum[i] << ' ';
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int ans = 0;
        int z = 9;
        int temp = 1;
        while(n > 0){
            while(z > n){
                z--;
                }
            ans += temp * z;
            n -= z;
            temp *= 10;
            z--;
        }
        cout << ans << endl;
    }
    return 0;
}