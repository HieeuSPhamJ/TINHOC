#include<bits/stdc++.h>
using namespace std;

int n, m, k;

long long cal(long long x){
    return x * 2 * (x / 2) - ;
}

int main(){
    cin >> n >> m >> k;
    m -= n;
    int left = 0;
    int right = 1e9;
    int mid = (left + right) / 2;
    while(left <= right){
        mid = (left + right) / 2;
        cout << left << ' ' << mid << ' ' << right << ' ' << cal(mid) << endl;
        if (cal(mid) <= m){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << mid + 1;
}