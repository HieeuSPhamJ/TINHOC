#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 3 * 1e5 + 10;

ii a[maxN];
int newA[2 * maxN];
map <int,int> conv;
int prefixSum[2 * maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    set <int> tempConv;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        tempConv.insert(a[i].fi);
        tempConv.insert(a[i].se);
    }

    int count = 1;
    for (auto i: tempConv){
        conv[i] = count;
        // cout << i << " " << count << endl;
        count++;
    }

    for (int i = 1; i <= n; i++){
        a[i].fi = conv[a[i].fi];
        a[i].se = conv[a[i].se];
        
        prefixSum[a[i].fi] += 1;
        prefixSum[a[i].se + 1] -= 1;
        cout << a[i].fi << " " << a[i].se << endl;
    }

    for (int i = 1, temp = 0; i <= 2 * n; i++){
        temp += prefixSum[i];
        newA[i] = temp;
    }

    for (int i = 1; i <= n; i++){
        cout << newA[i] << ' ';
    }
    
    return 0;
}