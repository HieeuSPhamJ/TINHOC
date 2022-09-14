#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int prefix[maxN];

int sum(int left, int right){
    return prefix[right] - prefix[left - 1];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            prefix[i] = prefix[i - 1] + a[i];        
        }
        int ans = 0;

        for (int j = 1, cap = 0; j <= n; j++){
            cap += a[j];
            // cout << "Cap: " << cap << endl;
            int lastId = j;
            bool check = 1;
            while(lastId < n){
                int left = lastId + 1;
                int right = n;
                int mid = (left + right) / 2;
                // cout << lastId << endl;
                while(left <= right){
                    mid = (left + right) / 2;
                    int s = sum(lastId + 1, mid);
                    // cout << left << " " << mid << " " << right << " " << s << endl;
                    if (s < cap){
                        left = mid + 1;
                    }
                    else if (s > cap){
                        right = mid - 1;
                    }
                    else{
                        break;
                    }
                }
                // cout << lastId + 1 << " " << mid << endl;
                if (sum(lastId + 1, mid) == cap){
                    lastId = mid;
                    // cout << "-" << endl;
                }
                else{
                    check = 0;
                    break;
                }
            }
            if (check == 1){
                // cout << "*" << endl;
                ans++;
            }
        }

        cout << ans << endl;

    }
    return 0;
}