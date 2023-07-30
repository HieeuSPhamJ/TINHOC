#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 35010;


int n, k;
int a[maxN];
int dp[maxN];
int old[maxN];
int L = 1;
int R = 1;
int cnt[maxN];
int CNT = 1;

void printseg(){
    cout << L << "-" << R << " " << CNT << endl;
    for (int i = 1; i <= n; i++){
        cout << cnt[i] << " ";
    }
    cout << endl;
}
 

int getcost(int l, int r){ 
    // printseg();
    while(L < l){
        cnt[a[L]]--;
        if (cnt[a[L]] == 0){
            CNT--;
        }
        L++;    
        // printseg();
    }
    while(l < L){
        L--;
        cnt[a[L]]++; 
        if (cnt[a[L]] == 1){
            CNT++;
        }
        // printseg();
    }
    while(r < R){
        cnt[a[R]]--;
        if (cnt[a[R]] == 0){
            CNT--;
        }
        R--;  
        // printseg();
    }
    while(R < r){
        R++;
        cnt[a[R]]++;  
        if (cnt[a[R]] == 1){
            CNT++;
        }
        // printseg();
    }
    return CNT;
}

void cal(int l, int r, int optl, int optr){
    if (l > r){
        return;
    }
    int i = (l + r) / 2;

    int opt = 1;
    // cout << i << ": " << optl << " " << min(i,optr) << endl;
    for (int j = optl; j <= min(i,optr); j++){
        if (dp[i] < old[j - 1] + getcost(j,i)){
            dp[i] = old[j - 1] + getcost(j,i);
            opt = j;
            // cout << " " << j << " " << old[j - 1] << " " << getcost(j,i) << " " << dp[i] << endl;
        }
    }

    // cout << l << " " << i - 1 << " " << optl << " "  << opt << endl;
    // cout << i + 1 << " " << r << " " << opt << " "  << optr << endl;

    cal(l, i - 1, optl, opt);
    cal(i + 1, r, opt, optr);
}

void print(){
    for (int i = 1; i <= n; i++){
        if (old[i] == 1e18){
            cout << "inf ";
            continue;
        }
        cout << old[i] << " ";
    }
    cout << endl;
}



signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }   

    cnt[a[1]]++;

    // cout << getcost(1,2) << endl;
    // cout << getcost(1,1) << endl;
    // cout << getcost(1,3) << endl;
    // cout << getcost(1,4) << endl;

    for (int j = 1; j <= k; j++){
        // cout << "With: " << j << endl;
        cal(1,n,1,n);
        for (int i = 1; i <= n; i++){
            old[i] = dp[i];
            dp[i] = 0;
        }
        // print();
    }

    cout << old[n];

    return 0;
}


/*
1 2 3 4 5 6 7 8
7 7 8 7 7 8 1 7

1 1 2 2 2 2 3 3

*/