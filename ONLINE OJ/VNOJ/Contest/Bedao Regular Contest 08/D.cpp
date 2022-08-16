#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define f first
#define s second
#define int long long
#define endl '\n'
using namespace std;

const int inf = 1e18;
const int maxN = 1e6 + 10;

int n;
int a[maxN];
ii b[maxN];
int seg[maxN * 4];
int minLeft[maxN];
int minRight[maxN];

bool cmp(ii x, ii y){
    return x.s < y.s;
}

void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        cout << left << ":" << val << endl;
        seg[i] = val;
        return;
    }

    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);

    seg[i] = max(seg[2 * i + 1], seg[2 * i]);
    
}


int get(int i, int left, int right, int _left, int _right){
        if (_right < left or right < _left){
            return 0;
        }
        if (_left <= left and right <= _right){
            return seg[i];
        }

        int mid = (left + right) / 2;

        return max(get(2 * i, left, mid, _left, _right), get(2 * i + 1, mid + 1, right, _left, _right));
}

void reset(){
    for (int i = 0; i < maxN * 4; i++){
        seg[i] = 0;
    }
}
signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;

    // for (int i = 0)
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = {a[i], i};
    }

    sort(b + 1, b + 1 + n);
    for (int i = 1, j = 0; i <= n; i++){
        if (b[i].f != b[i - 1].f){
            j++;
        }
        b[i].f = j;   
    }

    sort(b + 1, b + 1 + n, cmp);

    for (int i = 1; i <= n; i++){
        a[i] = b[i].f;
        // cout << a[i] << ' ';
    }
    // cout << endl;

    reset();
    for (int i = 1; i <= n; i++){
        if (a[i] == 1){
            minLeft[i] = i;
        }
        int m = get(1,1,n,1,a[i] - 1);
        cout << 1 << " " << a[i] - 1 << " " << m << endl;
        minLeft[i] = m;
        update(1,1,n,a[i],i);
    }

    // reset();
    // for (int i = n; i >= 1; i--){
    //     if (a[i] == 1){
    //         minRight[i] = i;
    //     }
    //     minRight[i] = get(1,1,n,1, i - 1);
    //     update(1,1,n,a[i],1);
    // }

    for (int i = 1; i <= n; i++){
        cout << minLeft[i] << ' ';
    }
    cout << endl;

    for (int i = 1; i <= n; i++){
        cout << minRight[i] << ' ';
    }
    cout << endl;




    return 0;
}