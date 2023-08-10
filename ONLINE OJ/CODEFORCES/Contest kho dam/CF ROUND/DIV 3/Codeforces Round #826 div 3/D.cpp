#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <int,ii>
#define fi first
#define se second
#define num first
#define mi second.first
#define ma second.second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 262244;

int a[maxN];
iii inf = {-1,{-1,-1}};

iii dp(int left, int right){
    if (left == right){
        return {0, {a[left], a[left]}};
    }
    int mid = (left + right) / 2;
    iii t1 = dp(left, mid);
    iii t2 = dp(mid + 1, right);
    if (t1 == inf or t2 == inf){
        return inf;
    }
    if (t1.ma < t2.mi){
        // cout << left << " " << mid << " " << right << endl;
        // cout << t1.mi << " " << t1.ma << " - " << t2.mi << " " << t2.ma << endl;
        // cout << "NO" << endl;
        return {t1.num + t2.num, {min(t1.mi, t2.mi), max(t1.ma, t2.ma)}};
    }
    if (t2.ma < t1.mi){
        // cout << left << " " << mid << " " << right << endl;
        // cout << t1.mi << " " << t1.ma << " - " << t2.mi << " " << t2.ma << endl;
        // cout << "YES" << endl;
        return {t1.num + t2.num + 1, {min(t1.mi, t2.mi), max(t1.ma, t2.ma)}};
    }
    return inf;
        
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        cout << dp(1,n).num << endl;
    }
    return 0;
}   