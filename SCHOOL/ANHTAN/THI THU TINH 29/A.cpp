#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;

int n;
int a[maxN];
int ai[maxN];
ii b[maxN];
int farLeft[maxN];
int farRight[maxN];
int segMin[maxN * 4];
int segMax[maxN * 4];

bool cmp(ii x, ii y){
    return x.se < y.se;
}
 
void updateMax(int i, int left, int right, int index, int val){
    // cout << left << ' ' << right << endl;
    if (index < left or right < index){
        return;
    }
    if (left == right){
        // cout << "#" << endl;
        segMax[i] = val;
        return;
    }
 
    int mid = (left + right) / 2;
 
    updateMax(2 * i, left, mid, index, val);
    updateMax(2 * i + 1, mid + 1, right, index, val);
 
    segMax[i] = max(segMax[2 * i], segMax[2 * i + 1]);
    
}

void updateMin(int i, int left, int right, int index, int val){
    // cout << left << ' ' << right << endl;
    if (index < left or right < index){
        return;
    }
    if (left == right){
        // cout << "#" << endl;
        segMin[i] = val;
        return;
    }
 
    int mid = (left + right) / 2;
 
    updateMin(2 * i, left, mid, index, val);
    updateMin(2 * i + 1, mid + 1, right, index, val);
 
    segMin[i] = min(segMin[2 * i], segMin[2 * i + 1]);
    
}

int getMax(int i, int left, int right, int _left, int _right){
    if (_right < left or right < _left){
        return -inf;
    }
    if (_left <= left and right <= _right){
        return segMax[i];
    }
 
    int mid = (left + right) / 2;
 
    return max(getMax(2 * i, left, mid, _left, _right), getMax(2 * i + 1, mid + 1, right, _left, _right));
 
}
 
int getMin(int i, int left, int right, int _left, int _right){
    // cout << left << ' ' << right << endl;
    if (_right < left or right < _left){
        // cout << i << '-' << endl;
        return inf;
    }
    if (_left <= left and right <= _right){
        // cout << i << '+' << endl;
        return segMin[i];
    }
 
    int mid = (left + right) / 2;
 
    return min(getMin(2 * i, left, mid, _left, _right), getMin(2 * i + 1, mid + 1, right, _left, _right));
    
}

void init(){
    for (int i = 0; i < 4 * maxN; i++){
        segMin[i] = n + 1;
    }

    sort(b + 1, b + 1 + n);
    for (int i = 1, j = 0; i <= n; i++){
        if (b[i].fi != b[i - 1].fi){
            j++;
        }
        b[i].fi = j;
        
    }
 
    sort(b + 1, b + 1 + n, cmp);
 
    for (int i = 1; i <= n; i++){
        ai[i] = b[i].fi;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = {a[i], i};
        // dp[1][i] = 1;
    }

    b[0] = {0, 0};
    init();

    for (int i = 1; i <= n; i++){
        int far = 1;
        if (ai[i] != 1){
            far = getMax(1,1,n,1,ai[i] - 1);
            // cout << far << endl;
            far++;   
        }
        updateMax(1,1,n,ai[i],i);
        farLeft[i] = far;
    }
    for (int i = n; i >= 1; i--){
        int far = n;
        if (ai[i] != 1){
            far = getMin(1,1,n,1,ai[i] - 1);
            // cout << far << endl;
            far--;   
        }
        updateMin(1,1,n,ai[i],i);
        farRight[i] = far;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++){
        ans = max(ans, a[i] * (abs(farLeft[i] - i) + abs(farRight[i] - i) + 1));
    }

    cout << ans;

    return 0;
}