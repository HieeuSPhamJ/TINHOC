#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const long long maxN = 400;

long long sumCol[maxN][maxN];
long long tempSum[maxN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, m;
    cin >> n >> m;

    for (long long i = 1; i <= n; i++){
        for (long long j = 1; j <= m; j++){
            long long inp;
            cin >> inp;
            sumCol[i][j] = sumCol[i - 1][j] + inp;
        }
    }
    long long ans = -1e18;
    for (long long up = 1; up <= n; up++){
        for (long long down = up; down <= n; down++){
            for (long long i = 1; i <= m; i++){
                tempSum[i] = sumCol[down][i] - sumCol[up - 1][i];
            }
            long long sum = -1e18;
            for (long long i = 1; i <= m; i++){
                sum = max(tempSum[i], sum + tempSum[i]);
                ans = max(ans, sum);
            }
            
        }
    }
    cout << ans;

    return 0;
}