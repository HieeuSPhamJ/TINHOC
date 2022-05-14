    #include<bits/stdc++.h>
    using namespace std;

    const long long maxI = 11;
    const long long maxK = 85;
    const long long maxState = 3;
    const long long mod = 1000000007;


    long long dp[maxI][maxK][maxK][maxK][maxState];

    void solve(){
        long long k;
        string n;
        cin >> n >> k;
        if (k > 83){
            cout << 0;
            return;
        }
        long long len = n.size();

        for (long long i = 0; i < maxI; i++) {
            for (long long thatNum = 0; thatNum <= k; thatNum++) {
                for (long long sum = 0; sum <= k; sum++) {
                    for (long long pro = 0; pro <= k; pro++) {
                        for (long long state = 0; state < maxState; state++) {
                            dp[i][thatNum][sum][pro][state] = 0;
                        }
                    }
                }
            }
        }

        for (long long i = 1; i <= 9; i++){
            long long state = 0;
            if (i == n[0] - '0'){
                state = 1;
            }
            else if (i > n[0] - '0'){
                state = 2;
            }
            dp[1][i % k][i % k][i % k][state]++;
        }    

        for (long long i = 1; i < len; i++){
            for (long long thatNum = 0; thatNum < k; thatNum++){
                for (long long sum = 0; sum < k; sum++){
                    for (long long pro = 0; pro < k; pro++){
                        for (long long state = 0; state <= 2; state++){
                            if (dp[i][thatNum][sum][pro][state] == 0){
                                continue;
                            }
                            for (long long dig = 0; dig <= 9; dig++){
                                long long newState = state;
                                if (state == 1){
                                    if (dig < n[i] - '0'){
                                        newState = 0;
                                    }
                                    if (dig > n[i] - '0'){
                                        newState = 2;
                                    }
                                }
                                long long ans = dp[i][thatNum][sum][pro][state];
                                (dp[i + 1][(thatNum * 10 + dig) % k][(sum + dig) % k][(pro * dig) % k][newState] += ans) %= mod;

                            }
                            
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for (long long i = 1; i <= len; i++){
            for (long long state = 0; state <= (i < len ? 2 : 1); state++){
                    (ans += dp[i][0][0][0][state]) %= mod;
            }
        }
        cout << ans;

    }

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        long long test;
        cin >> test;
        while(test--){
            solve();
            cout << endl;
        }
        return 0;
    }