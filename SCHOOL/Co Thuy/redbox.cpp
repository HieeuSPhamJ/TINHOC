#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int inf = 1e18;

int n, k, x, y;
int a[maxN]; 
int seg[maxN * 4];
int realVal[maxN];
map <int,int> conv;
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
    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
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
    return max(t1,t2);
}

void push(int i, int val){
    update(1,1,n,i,val);
} 
int GET(){
    int left = 1;
    int right = n;
    while(left <= right){
        int x = (left + right) / 2;
        
    }
}

void nenso(){
    set <int> sto;
    for (int i = 1; i <= n; i++){
        sto.insert(a[i]);
    }
    int cnt = 1;
    for (auto i: sto){
        conv[i] = cnt;
        realVal[cnt] = i;
        cnt++;
    }
    for (int i = 1; i <= n; i++){
        a[i] = conv[a[i]];
    }
}

signed main(){
    // freopen("redbox.INP", "r", stdin);
    // freopen("redbox.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> x >> y;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    nenso();
    int left = 1;
    int right = 1;
    int ans = 0;
    push(a[1],1);

    while(left <= right and right <= n){
        cout << "LEFT: " << left << endl;
        while(right <= n and (right - left) + 1 - GET() <= k){
            cout << right << " " << (right - left) + 1 - GET() << endl;
            right++;
            push(a[right], 1);
        }
        cout << (right - left) + 1 - GET() << endl;
        if ((right - left) + 1 - GET() > k){
            push(a[right], -1);
            right--;
        }
        int len = (right - left) + 1;
        ans = max(ans, len);
        cout << left << " " << right << " " << GET() << endl;
        left++;
        while (left > right){
            right++;
        }
    }
    cout << ans;
    return 0;
}

/*
*/