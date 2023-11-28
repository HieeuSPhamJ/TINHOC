#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int maxVal = 210;
int n, d;
int a[maxN];
int temp[maxVal];

const int inf = 1e18;

int seg[maxVal * 4];


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

void UP(int i, int val){
    update(1,1,maxVal,i + 1, val);
}

int GET(int l, int r){
    return get(1,1,maxVal, l, r);
}


double trungvivippro(int x){
    // cout << "index: " << x << endl;
    // for (int i = 0; i <= 200; i++){
    //     if (get(1,1,n,i,i)){
    //         cout << i << ": " << get(1,1,n,i,i) << " ";
    //     }
    // }
    // cout << endl;
    int left = 1;
    int right = maxVal;
    int tans = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = GET(1,mid);
        // cout << left << " " << mid << " " << right << endl;
        // cout << cnt << endl;
        if (cnt < x){
            left = mid + 1;
        }
        else{
            right = mid - 1;
            tans = mid;
        }
    }
    return tans - 1;

}

signed main(){
    // freopen("input.inp", "r", stdin);
    // freopen("B.out", "w", stdout);
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
        UP(a[j], 1);
    }

    for (int i = d + 1; i <= n; i++){

        // double t = trungvi();
        double t = trungvivippro(d / 2 + 1);
        if (d % 2 == 0){
            t += trungvivippro(d / 2);
            t /= 2;
        }
        // cout << t << " " << t * 2 << " : " << a[i] << endl;

        if (a[i] >= 2 * t){
            // cout << "#" << endl;
            ans++;
        }

        temp[a[i]]++;
        temp[a[i - d]]--;
        UP(a[i], 1);
        UP(a[i - d], -1);

    }
 
    cout << ans;

    return 0;
}