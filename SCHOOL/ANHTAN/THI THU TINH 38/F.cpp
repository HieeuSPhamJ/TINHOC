#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, d;
int a[maxN];
int temp[1010];

double trungvi(){
    int mid1 = (d + 1) / 2;
    int mid2 = d - mid1 + 1;
    int a = -1;
    int b = -1;

    // cout << "MID: " << mid1 << " " << mid2 << endl;

    for (int j = 1, count = 0; j <= 1010; j++){
        count += temp[j];
        // cout << j << " " << temp[j] << endl;
        if (a == -1 and count >= mid1){
            a = j;
        } 
        if (b == -1 and count >= mid2){
            b = j;
        } 
        if (a != -1 and b != -1){
            break;
        }
    }
    // cout << a << " " << b << endl;
    double t = (double)(a + b) / 2.0;
    // cout << "TRUNGVI: " << t << endl;
    return t;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> d;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int ans = 0;

    for (int j = 1; j <= d; j++){
        temp[a[j]]++;
    }

    for (int i = d + 1; i <= n; i++){

        double t = trungvi();

        // cout << t << " " << t * 2 << " : " << a[i] << endl;

        if (a[i] >= 2 * t){
            // cout << "#" << endl;
            ans++;
        }
        temp[a[i]]++;
        temp[a[i - d]]--;
    }
    cout << ans;

    return 0;
}