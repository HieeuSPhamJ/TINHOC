#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;

int n, m;
int a[maxN];
int worker[maxN];
int checkExit[maxN];

void printWorker(){
    for (int i = 1; i <= n; i++){
        cout << worker[i] << ' ';
    }
    cout << endl;
}

bool check(int time){
    int count = 0;
    for (int i = 1; i <= max(n, m); i++){
        worker[i] = 0;
        checkExit[i] = 0;
    }
    for (int i = 1; i <= m; i++){
        
        if (worker[a[i]] + 1 <= time){
            worker[a[i]]++;
            checkExit[i] = 1;
            count++;
            // cout << i << '-' << a[i] << ' ';
        }
        // printWorker();
    }
    // cout << endl;
    int w = 1;
    for (int i = 1; i <= m; i++){
        if (checkExit[i] == 0){
            // cout << i << ' ';
            while(worker[w] + 2 > time){
                w++;
            }
            if (w > n){
                break;
            }

            if (worker[w] + 2 <= time){
                // cout << i << '-' << w << ' ';
                worker[w]+=2;
                checkExit[i] = 1;
                count++;
            }
        }
        // printWorker();
    }
    // cout << endl;
    for (int i = 1; i <= m; i++){
        if (checkExit[i] == 0){
            return 0;
        }
    }
    return 1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            cin >> a[i];
        }

        int left = 1;
        int right = 1e18;
        int ans = 1e18;
        while(left <= right){
            int mid = (left + right) / 2;
            // cout << left << " " << mid << " " << right << endl;
            if (check(mid)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        int temp = check(3);
        // cout << temp << ' ';

        cout << ans << endl;
    }
    return 0;
}