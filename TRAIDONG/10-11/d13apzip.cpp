#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int n;
int a[maxN];
int prefix[maxN];
int forw[maxN];
int down[maxN];

int random(int left = 0, int right = 1e8){
    if (left == right){
        return left;
    }
    return (rd() % (right - left + 1)) + left;
}

int sum(int l, int r){
    return prefix[r] - prefix[l - 1];
}

void sublon(){
    for (int i = 1, last = 0; i <= n; i++){
        if (a[i] == 0){
            last = i;
        }
        down[i] = abs(i - last);
    }
    for (int i = n, last = n + 1; i >= 1; i--){
        if (a[i] == 0){
            last = i;
        }
        forw[i] = abs(i - last);
    }
    
    // for (int i = 1; i <= n; i++){
    //     cout << forw[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << down[i] << " ";
    // }
    // cout << endl;

    int ans = sum(1,n);
    int left = 1;
    int right = n;
    stack <int> suck;

    for (int i = 1; i <= n; i++){
        suck.push(ans);
        if (forw[left] >= down[right]){
            ans -= a[right];
            right--;
        }
        else{
            ans -= a[left];
            left++;
        }
    }

    while(suck.empty() == 0){
        cout << suck.top() << " ";
        suck.pop();
    }
}

void subbe(){
    for (int i = 1; i <= n; i++){
        int ans = 0;
        for (int j = i; j <= n; j++){
            // cout << j - i + 1 << " " << j << endl;
            ans = max(ans, sum(j - i + 1, j));
        }
        cout << ans << " ";
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        a[i] = x - '0';
        prefix[i] = prefix[i - 1] + a[i];
    }

    if (n >= 1e5){
        sublon();
    }
    else{
        subbe();
    }
    

    
    return 0;
}