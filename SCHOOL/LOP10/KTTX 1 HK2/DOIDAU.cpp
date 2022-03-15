#include<bits/stdc++.h>
using namespace std;

const int maxN = 25;

int n;
long long countAns = 0;
int a[maxN];

void backTracking(int index, long long sum){
    if (index > n){
        if (sum == 0){
            countAns++;
        }
        return;
    }
    backTracking(index + 1, sum + a[index]);
    backTracking(index + 1, sum - a[index]);

}

int main(){
    freopen("DOIDAU.INP", "r", stdin);
    freopen("DOIDAU.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    backTracking(1, 0);
    cout << countAns;
    return 0;
}