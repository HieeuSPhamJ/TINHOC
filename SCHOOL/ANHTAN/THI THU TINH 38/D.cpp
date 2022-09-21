#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;
int a[maxN];
int prefix[maxN];
int dp[maxN][12];


int seg[maxN * 4];

void update(int index, int left, int right, int id, int value){
    // cout << id << " " << left << " " << right << endl;
    if (id < left or right < id){
        return;
    }
    if (left == right){
        seg[index] += value;
        return;
    }
    int mid = (left + right) / 2;
    update(index * 2, left, mid, id, value);
    update(index * 2 + 1, mid + 1, right, id, value);
    seg[index] = min(seg[index * 2], seg[index * 2 + 1]);
}

int get(int index, int left, int right, int _left, int _right){
    if (_right < left or right < _left){
        return inf;
    }
    if (_left <= left and right <= _right){
        return seg[index];
    }

    int mid = (left + right) / 2;

    int t1 = get(index * 2, left, mid, _left, _right);
    int t2 = get(index * 2 + 1, mid + 1, right, _left, _right);

    return min(t1,t2);
}   

int sum(int left, int right){
    return prefix[right] - prefix[left - 1];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        update(1,1,n,i,a[i]);
        prefix[i] = prefix[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <=11; j++){
            dp[i][j] = inf;
        }  
    }

    dp[1][1] = a[1];

    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= min(i - 1,10ll); j++){
            dp[i][1] = min(dp[i][1], dp[i - 1][j] + a[i]);
        }   
        for (int j = 2; j <= min(i,10ll); j++){
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i]);
        }   
        if (i >= 10){
            dp[i][10] -= get(1,1,n,i - 9, i);
        }
    }

    int ans = inf;
    
    for (int i = 1; i <= 10; i++){
        ans = min(ans, dp[n][i]);
    }

    cout << ans;
    return 0;
}