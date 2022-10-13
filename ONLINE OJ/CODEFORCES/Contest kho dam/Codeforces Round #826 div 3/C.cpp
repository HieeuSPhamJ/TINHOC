#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2010;

int a[maxN];
int prefix[maxN];

// int sum(int left, int right){
//     return prefix[right] - prefix[left - 1];
// }

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
        int sum = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];
            // prefix[i] = prefix[i - 1] + a[i];
        }
        int ans = n;
        // cout << "TEST: " << endl;
        for (int i = 2; i * i <= sum; i++){
            if(sum % i == 0){
                int check = 0;
                int temp = 0;
                for (int j = 1, count = 0; j <= n; j++){
                    check += a[j];
                    count++;
                    if(check == i){
                        temp = max(temp , count);
                        check = count = 0;
                    }
                }
                if(check == 0){
                    ans = min(ans , temp);
                }
                if(i != sum / i){
                    int check = 0;
                    int temp = 0;
                    for (int j = 1, count = 0; j <= n; j++){
                        check += a[j];
                        count++;
                        if(check == sum / i){
                            temp = max(temp , count);
                            check = count = 0;
                        }
                    }
                    if(check == 0){
                        ans = min(ans , temp);
                    }
                }
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}