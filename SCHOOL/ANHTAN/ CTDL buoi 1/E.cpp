#include<bits/stdc++.h>
using namespace std;

const int maxM = 30410;
const int maxN = 2110;


long long prefix[maxN][maxM];

int calLen(int ix, int iy, int x, int y){
    return ceil(sqrt(pow(ix - x, 2) + pow(iy - y, 2)));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++){
        int y, x, r, val;
        cin >> y >> x >> r >> val;
        for (int i = 1; i <= x + r; i++){
            int left = y;
            int right = 1e9;
            // cout << i << "\n";
            int tempY = -1;
            while(left <= right){
                int mid = (left + right) / 2;
                // cout << left << ' ' << mid << ' ' << right << ' ' << calLen(x, y, i, mid) << "\n";
                if (calLen(x, y, i, mid) <= r){
                    left = mid + 1;
                    tempY = mid;
                }
                else{
                    right = mid - 1;
                }
            }

            int dot1X = i;
            int dot1Y = tempY;

            int diffX = (dot1X - x);
            int diffY = (dot1Y - y);

            
            int dot2X = dot1X;
            int dot2Y = y - diffY;

            

            if (calLen(0, 0, dot1X, dot1Y) > calLen(0, 0, dot2X, dot2Y)){
                swap(dot1X, dot2X);
                swap(dot1Y, dot2Y);
            }
            dot1X = max(1,dot1X);
            dot2X = max(1,dot2X);
            dot1Y = max(1,dot1Y);
            dot2Y = max(1,dot2Y);
            // cout << dot1X << ' ' << dot1Y << "\n";
            // cout << dot2X << ' ' << dot2Y << "\n";
            // cout << "-" << "\n";
            prefix[dot1X][dot1Y] += val;
            prefix[dot2X][dot2Y + 1] -= val;


        }
        // cout << "NEXT CIR" << "\n";


    }
    
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         cout << prefix[i][j] << ' ';
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";
    // cout << "$";

    int ans = 0;
    int count = 0;
    for (int i = 1; i <= n; i++){
        long long tempVal = 0;
        for (int j = 1;j <= m; j++){
            tempVal += prefix[i][j];
            // cout << tempVal << ' ';
            if (tempVal > ans){
                ans = tempVal;
            }
            if (tempVal == ans){
                count++;
            }
        }
        // cout << "\n";
    }
    cout << ans << "\n" << count;

    return 0;
}