#include<bits/stdc++.h>
using namespace std;

struct cus{
    int x;
    int y;
};

cus a[110];

const long long inf = 1e8;
int n;
long long time1 = 0;
long long time2 = 0;
long long ans =  0;
long long tempTime = 0;


void Recur1(long long time1, long long time2, int index){
    // cout << "# " << time1 << " " << time2 << " " << index << endl;
    tempTime = min(tempTime, max(time1, time2));
    if (index <= n){
        // cout << tempTime << endl;
        if (time2 - a[index].y >= 0){
            Recur1(time1 + a[index].x, time2 - a[index].y, index + 1);
        }
        Recur1(time1, time2, index + 1);
    }
}



int main(){
    freopen("SPC4.INP", "r", stdin);
    freopen("SPC4.OUT", "w", stdout);
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        time1  = 0;
        time2  = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i].x;
            time1 += a[i].x;
        }
        for (int i = 1; i <= n; i++){
            cin >> a[i].y;
            time2 += a[i].y;
        }
        // cout << time1 << ' ' << time2 << endl;
        ans = max(time1, time2);
        tempTime = inf;
        Recur1(0, time2, 1);    
        ans = min(tempTime, ans);
        cout << ans;
        cout << endl;
    }
    return 0;
}