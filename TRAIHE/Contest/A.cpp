#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int maxN = 1e5 + 10;

int n, k;
int a[maxN];
int ans[maxN];
int dp[maxN];
int countLimit = 0;

void backTrack(int i, int len){
    vector <int> temp;
    for (int j = i - 1; j >= 1; j--){
        if (a[j] * k == a[i]){
            temp.push_back(j);
        }
        countLimit++;
    }
    len++;
    ans[len] += temp.size();
    for (auto i: temp){
        backTrack(i, len);
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = -1;
    }
    for (int i = 2; i <= n; i++){
        backTrack(i, 1);
    }
    for (int i = 2; i <= n; i++){
        cout << ans[i] << ' ';
    }

    cout << endl;
    cout << countLimit;
    return 0;
}