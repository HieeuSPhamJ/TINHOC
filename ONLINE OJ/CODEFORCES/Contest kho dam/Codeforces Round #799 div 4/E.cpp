#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 2 * 1e5 + 10;

int sum[maxN];
int a[maxN];
int farRight[maxN];
int farLeft[maxN];

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }

        int far = -1;
        
        for (int i = 1; i <= n; i++){
            if (a[i] == 1){
                far = 0;
            }

            farLeft[i] = far;


            if (far != -1){
                far++;
            }
        }

        far = -1;

        for (int i = n; i >= 1; i--){
            if (a[i] == 1){
                far = 0;
            }

            farRight[i] = far;


            if (far != -1){
                far++;
            }
        }

        // for (int i = 1; i <= n; i++){
        //     cout << farRight[i] << ' ';
        // }
        // cout << endl;

        // for (int i = 1; i <= n; i++){
        //     cout << farLeft[i] << ' ';
        // }
        // cout << endl;

        // for (int i = 1; i <= n; i++){
        //     cout << sum[i] << ' ';
        // }
        // cout << endl;

        int tsum = sum[n] - sum[0];
        // int count = 0;
        int left = 1;
        int right = n;

        while(tsum != m){
            // cout << tsum << ' ' << left << ' ' << right << endl;
            if (left > right){
                break;
            }
            if (farRight[left] == -1 or farLeft[right] == -1){
                break;
            }
            if (farRight[left] < farLeft[right]){
                left++;
            }
            else{
                right--;
            }

            tsum = sum[right] - sum[left - 1];

        }

        if (sum[right] - sum[left - 1] != m){
            cout << -1;
            cout << endl;
            continue;
        }

        cout << n - (right - left + 1);

        cout << endl;
        // cout << "----" << endl;
    }
    

    return 0;
}


