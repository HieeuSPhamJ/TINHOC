#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 3010;

int a[maxN];
int dp[maxN][maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        char inp;
        cin >> inp;
        if (inp == '<'){
            a[i] = 0;
        }
        else if (inp == '>'){
            a[i] = 1;
        }
    }

    for (int i = 1; i <= n; i++){
        dp[1][i]++;
    }

    for (int i = 2; i <= n; i++){
        if (a[i])
    }

    return 0;
}