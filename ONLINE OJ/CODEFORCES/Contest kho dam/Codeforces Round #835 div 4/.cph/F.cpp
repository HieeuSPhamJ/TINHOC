#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rvall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 3 * 1e5 + 10;

int prefix[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        // cout << "=========TEST=========" << endl;
        int n, goal, day;
        cin >> n >> goal >> day;
        vector <int> a;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(rvall(a));
        int temp = 0;
        for (int i = 1; i <= min(n,day); i++){
            temp += a[i - 1];
        }
        prefix[0] = a[0];
        for (int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + a[i];
        }
        for (int i = n; i <= day; i++){
            prefix[i] = prefix[i - 1];
        }
        // for (int i = 0; i <= max(day, n); i++){
        //     cout << prefix[i] << " ";
        // }
        // cout << endl;
        if (temp >= goal){
            cout << "Infinity" << endl;
            continue;
        }
        temp = a[0] * day;
        if (temp < goal){
            cout << "Impossible" << endl;
            continue;
        }
        int ans = 0;

        int left = 1;
        int right = day;
        while(left <= right){
            int mid = (left + right) / 2;
            // cout << left << " " << mid << " " << right << endl;
            int tans = 0;
            int d = mid + 1;
            tans += day / d * prefix[d - 1];
            if (day % d != 0){    
                tans += prefix[day % d - 1];
            }
            // cout << tans << endl;
            if (tans >= goal){
                left = mid + 1;
                ans = mid;
            }
            else{
                right = mid - 1;
            }
        }

        cout << ans << endl;
        
    }
    return 0;
}