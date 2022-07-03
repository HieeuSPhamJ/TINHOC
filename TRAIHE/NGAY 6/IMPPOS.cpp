#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e9;

vector <ii> lists;
vector <int> listCal;

int seg[maxN * 4];
ii b[maxN];
int a[maxN];
int dp[maxN];

bool cmp(ii x, ii y){
    return x.s < y.s;
}

 
void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] = val;
        return;
    }
 
    int mid = (left + right) / 2;
 
    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
 
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    
}
 
int get(int i, int left, int right, int _left, int _right){
    if (_right < left or right < _left){
        return -inf;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }
 
    int mid = (left + right) / 2;
    return max(get(2 * i, left, mid, _left, _right), get(2 * i + 1, mid + 1, right, _left, _right));
 
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        lists.push_back({x, y});
    }

    sort(lists.begin(), lists.end());

    

    for (int i = 1; i <= lists.size(); i++){
        a[i] = lists[i - 1].s;
        // cout << a[i] << ' ';
    }

    for (int i = 1; i <= lists.size(); i++){
        cin >> a[i];
        b[i] = {a[i], i};
    }

    sort(b + 1, b + 1 + lists.size());
    for (int i = 1, j = 0; i <= lists.size(); i++){
        if (b[i].f != b[i - 1].f){
            j++;
        }
        b[i].f = j;
        
    }

    sort(b + 1, b + 1 + lists.size(), cmp);

    for (int i = 1; i <= lists.size(); i++){
        a[i] = b[i].f;
        // cout << a[i] << ' ';
    }

    n = lists.size();

    int ans = 0;
 
    for (int i = 1; i <= n; i++){
        int temp = get(1, 1, n, 1, a[i] - 1);
        if (temp == -inf){
            temp = 0;
        }
        if (dp[a[i]] == 0){
            dp[a[i]] = 1;
        }
        // cout << a[i] << ' ' << dp[a[i]] << ' ' << temp << endl;
        dp[a[i]] = max(dp[a[i]], 1 + temp);
        update(1, 1, n, a[i], dp[a[i]]);
        ans = max(ans, dp[a[i]]);
    }
 
    // for (int i = 1; i <= n; i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    cout << ans;


    
    
    return 0;
}