#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;


const int maxN = 3e5 + 10;
const int inf = 1e9;

int a[maxN];
int Start[maxN];
int End[maxN];
int tempAns[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int n, h;
    cin >> n >> h;
    
    for (int i = 1; i <= n; i++){
        cin >> Start[i] >> End[i]; 
    }
    tempAns[0] = tempAns[1] = 0;
    for (int i = 2; i <= n; i++){
        tempAns[i] = tempAns[i - 1] + (Start[i] - End[i - 1]);
        // cout << tempAns << ' ';
    }

    int ans = 0;

    for (int i = 1; i <= n; i++){
        int left = i;
        int right = n;
        while(left < right){
            int mid = (left + right + 1) / 2;
            if ((h - (tempAns[mid] - tempAns[i])) > 0){
                left = mid;
            }
            else{
                right = mid - 1;
            }

        }
        // cout << left << ' ' << right << endl;
        ans = max(ans, (End[left] - Start[i]) + (h - (tempAns[left] - tempAns[i])));


    }

    cout << ans;


    return 0;
}