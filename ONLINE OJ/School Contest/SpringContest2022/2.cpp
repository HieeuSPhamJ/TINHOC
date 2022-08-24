#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2000005; 
const int mod = 1000000007;

int notPrime[maxN + 10];
int ans[maxN];
priority_queue <int, vector <int>, greater <int>> myHeap;

void Eras(){
    for (int i = 2; i * i <= maxN; i++){
        if (notPrime[i] == 1){
            continue;
        }
        for (int j = 2; j * i <= maxN; j++){
            notPrime[i * j] = 1;
        }
    }

    for (int i = 2; i <= maxN; i++){
        if (notPrime[i] == 1){
            continue;
        }
        // cout << i << " ";
        myHeap.push(i);
    }
    // cout << endl;
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 1; i < maxN; i++){
        int t = myHeap.top();
        myHeap.pop();
        ans[i] = ans[i - 1] * t;
        ans[i] %= mod;
        myHeap.push(t * t);
    }

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Eras();
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}