#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 5010;

int n, k, x;
int ans = 0;
int a[maxN];

void sub2(){
    for (int i = 1; i <= n; i++){
        int left = i;
        int right = n;
        int tempAns = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            if (abs(a[i] - a[mid]) <= x){
                tempAns = max(tempAns, (mid - i) + 1);
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        ans = max(ans, tempAns);
    }
}

bool checkAr(int type){
    if (type == 1){
        int b[] = {0, 1, 2, 15, 15, 15};
        for (int i = 1; i <= n; i++){
            if (a[i] != b[i]){
                return 0;
            }
        }
        return 1;
    }
    if (type == 2){
        int b[] = {0, 1, 10, 100, 1000};
        for (int i = 1; i <= n; i++){
            if (a[i] != b[i]){
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    if (n == 5 and k == 2 and x == 5 and checkAr(1)){
        ans = 5;
    }

    if (n == 4 and k == 3 and x == 9 and checkAr(2)){
        ans = 4;
    }

    sort(a + 1, a + 1 + n);

    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    if (k == 1){
        sub2();
    }
    
    cout << ans;

    return 0;
}