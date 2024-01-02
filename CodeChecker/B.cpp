#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;


struct line{
    int a, b;
    line(int _a,int _b){
        a = _a;
        b = _b;
    }
    int val(int x){
        return a * x + b;
    }
};

void print(line x, char en = endl){
    cout << x.a << " " << x.b << en;
}
 
struct CHT{
    vector<line> st;
 
    bool sus(line d1,line d2,line d3){
        // print(d1);
        // print(d2);
        // print(d3);
        // cout << (double)(d1.b - d3.b) / (d3.a - d1.a)<< " | " << (double)(d1.b - d2.b) / (d2.a - d1.a) << endl;
        return  (double)(d1.b - d3.b) / (d3.a - d1.a) <= (double)(d1.b - d2.b) / (d2.a - d1.a);
    }
    void add(line x){
        // cout << "add: " << x.a << " " << x.b << endl;
        while(st.size()>1 and sus(st[st.size()-2],st.back(),x)){
            // cout << "pop: " << st.back().a << " " << st.back().b << endl;
            st.pop_back();
        }
        st.push_back(x);
    }
    int query(int x){
        int l = 0;
        int r = st.size()-1;
        int ans = 1e18;
        while(l <= r){
            int mid = (l + r) / 2;
            int now = st[mid].val(x);
            ans = min(ans, now);
            if (mid != 0 and now > st[mid-1].val(x)){
                r = mid - 1;
            }
            else if (mid + 1 != st.size() and now > st[mid+1].val(x)){
                l = mid + 1;
            }
            else{
                break;
            }
        }
        // cout << x << ": " << ans << endl;
        return ans;
    }
};

const int maxN = 2 * 1e5 + 10;

int dp[maxN];
int h[maxN];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++){
        cin >> h[i];
    }
    CHT cvh;

    dp[1] = 0;
    cvh.add(line(-2 * h[1],dp[1] + h[1] * h[1]));

    for (int i = 2; i <= n; i++){
        // cout << "With: " << i << endl;
        dp[i] = cvh.query(h[i]) + k + h[i] * h[i];
        cvh.add(line(-2 * h[i],dp[i] + h[i] * h[i]));
    }
    // for (int i = 1; i <= n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[n];

    return 0;
}