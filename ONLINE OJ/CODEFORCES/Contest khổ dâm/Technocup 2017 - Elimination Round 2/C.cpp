#include <bits/stdc++.h>
using namespace std;

struct dual {
    long long c;
    long long v;
};


long long n, k, s, t;

dual a[200005];
long long station[200005];

bool check (long long fuel) {
    long long time = 0;
    for (int i = 1; i <= k + 1; i++){
        // long long left = 0;
        long long right = station[i] - station[i-1];
        // long long tempTime = 1e10;
        // cout << "#" << station[i] << ' ' << station[i-1] << endl;
        // cout << "Station: " << right << endl;
        
        // while (left <= right){
        //     long long mid = (left + right) / 2;
        //     if ( (mid * 2 + station[i] - station[i-1] - mid) <= fuel ){
        //         left = mid + 1;
        //         tempTime = min (tempTime, mid + (station[i] - station[i-1] - mid) * 2);
        //     }
        //     else{
        //          right = mid - 1;
        //     }
        //     // cout << "Dir: " << left << ' ' << mid << ' ' << right<< ' ' << endl;
        //     // cout << "Time: " << time << ' ' << tempTime << endl;
        //     // cout << "---" << endl;
        // }

        long long mid = fuel - right;
        if (mid < 0){
            return 0;
        }
        long long tempTime = 2 * right - min(mid, right);

        time += tempTime;
        // cout << mid << ' ' << tempTime << ' ' << station[i] << endl;
        // cout << station[i] << ' ';
    }
    // cout << time << endl;
    // cout << "---------" << endl;
    return ( t >= time );
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> s >> t;
    station[0] = 0;
    station[k+1] = s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].c >> a[i].v;
    }
    
    for (int i = 1; i <= k; i++){
        cin >> station[i];
    }

    sort (station + 1, station + k + 1);

    // for (int i = 0; i <= k + 1; i++){
    //     cout << station[i] << ' ';
    // }

    long long left = 1;
    long long right = 1e9;

    while (left <= right) {
        long long mid = (left + right) / 2;
        // cout<< left << ' ' << mid << ' ' << right<<' '<< endl;
        if ( check(mid) ) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
        
    }
    
    // cout << check(8);

    // cout << endl;

    long long minPrice=1e9+1;
    for (int i = 1; i <= n; i++) {
        if ( left <= a[i].v ){
            minPrice = min (minPrice, a[i].c);
        }
    }
    if (minPrice == 1e9+1){
        cout << -1;
    }
    else {
        cout << minPrice;
    }

    return 0;
}