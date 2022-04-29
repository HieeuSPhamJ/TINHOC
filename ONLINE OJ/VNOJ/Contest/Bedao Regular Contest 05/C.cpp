#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[20];
int worker[20];
int ans = 0;
int lastWorker = -1;

void backtracking(int index){
    if (index > n){
        int tempAns = 0;
        for (int i = 1; i <= k; i++){
            tempAns = max(worker[i], tempAns);
            if (tempAns >= ans){
                return;
            }
            // cout << worker[i] << ' ';
        }
        // cout << endl;
        ans = min(tempAns, ans);
        return;
    }
    for (int i = 1; i <= k; i++){
        if (worker[i] + a[index] < ans){
            worker[i] += a[index];
            backtracking(index + 1);
            worker[i] -= a[index];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        worker[i] = 0;
        cin >> a[i];
        ans += a[i];
    }
    backtracking(1);
    cout << ans;

    return 0;
}
