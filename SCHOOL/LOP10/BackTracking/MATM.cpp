#include<bits/stdc++.h>
using namespace std;

struct pairStruct{
    long long x;
    long long y;
};

pairStruct a[40];
long long n, k;
long long countX = 0;

void BackTracking(long long index, long long sum){
    if (sum == k){
        countX++;
        return;
    }
    if (sum < k){
        for (int i = index; i <= n; i++){
            if (a[i].y > 0 and sum + a[i].x <= k){
                a[i].y--;
                BackTracking(i, sum + a[i].x);
                a[i].y++;
            }
        }
    }


}


int main(){
    freopen("MATM.INP", "r",stdin);
    freopen("MATM.OUT", "w",stdout);
    a[0].x = 0;
    a[0].y = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i].x;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i].y;
    }
    BackTracking(1, 0);
    cout << countX;

    return 0;
}