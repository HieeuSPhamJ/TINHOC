#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 3 * 1e5 + 10;
const int inf = 1e18;

int seg[maxN * 4];

void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] += val;
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = (seg[2 * i] + seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return (t1 + t2);
}

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        x = min(x,n);
        a[i] = x;
    }
    int ans = 0;
    priority_queue <ii,vector <ii>,greater <ii>> q;
    for (int i = 1; i <= n; i++){
        q.push({a[i],i});
        ans += get(1,1,n,1,a[i]);
        update(1,1,n,i,1);
        while(q.size() and q.top().fi <= i){
            update(1,1,n,q.top().se,-1);
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}