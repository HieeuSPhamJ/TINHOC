#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

bool check(int be, int bang, int lon){
    int l = be + 1;
    int r = be + bang;

    int mid = (be + lon + bang + 1) / 2;
    // cout << l << " " << mid << " " << r << " " << be << " " << bang << " " << lon << endl;
    if (l <= mid and mid <= r){
        return 1;
    }
    return 0;
}

signed main(){
    freopen("MEDIAN.INP", "r", stdin);
    freopen("MEDIAN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int lon = 0;
    int be = 0;
    int bang = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x == k){
            bang++;
        }
        else if (x > k){
            lon++;
        }
        else {
            be++;
        }
    }

    if (bang == 0){
        bang++;
    }
    
    int l = be + 1;
    int r = be + bang;

    int mid = (be + lon + bang + 1) / 2;

    if (l <= mid and mid <= r){
        cout << be + lon + bang - n << endl;
        return 0;
    }

    if (r < mid){
        // cout << "left" << endl;
        while(!check(be,bang,lon)){
            be++;
        }
        cout << be + lon + bang - n << endl;
    }
    else{
        // cout << "right" << endl;
        while(!check(be,bang,lon)){
            lon++;
        }
        cout << be + lon + bang - n << endl;
    }
    return 0;
}