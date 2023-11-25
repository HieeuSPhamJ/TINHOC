#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <int,ii>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1 * 1e6 + 10;
const int inf = 1e18;

vector <ii> listsA;
vector <ii> listsB;
int n, k;
int ans = 0;
int a[50];
int b[50];
int len = maxN - 10;
map <int, int> cnv;
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


void init(){
    listsA.push_back({0, 0});
    for (int DE = 1; DE <= n / 2; DE++){
        int x = a[DE], y = b[DE];
        vector <ii> temp;
        for (auto i: listsA){
            if (i.fi <= x){
                temp.push_back({x, i.se + y});
            }
        }
        for (auto i: temp){
            listsA.push_back(i);
        }
    }

    listsB.push_back({1e18, 0});
    for (int DE = n; DE >= n / 2 + 1; DE--){
        int x = a[DE], y = b[DE];
        vector <ii> temp;
        for (auto i: listsB){
            if (i.fi >= x){
                temp.push_back({x, i.se + y});
            }
        }
        for (auto i: temp){
            listsB.push_back(i);
        }
    }

    listsA[0] = {-1,-1};
    listsB[0] = {-1,-1};
}


void nenso(){
    set <int> count;
    count.insert(k);
    for (auto i: listsA){
        if (i.se != -1)
        count.insert(i.se);
        if (k - i.se > 0){
            count.insert(k - i.se);
        }
    }
    for (auto i: listsB){
        if (i.se != -1)
        count.insert(i.se);
    }
    int cnt = 1;
    for (auto i: count){
        cnv[i] = cnt;
        cnt++;
    }
}

void solve(){
    for (auto i: listsA){
        if (i.fi == -1){
            continue;
        }
        while(!listsB.empty() and listsB.back().fi >= i.fi){
            ii j = listsB.back();
            if (j.fi == -1){
                continue;
            }
            listsB.pop_back();
            update(1,1,len,cnv[j.se], 1);
        }
        int temp = get(1,1,len,max(1ll, cnv[k - i.se]),len);
        ans += temp;
    }
}

signed main(){
    freopen("GAME.INP", "r", stdin);
    freopen("GAME.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    init();
    sort(listsA.rbegin(), listsA.rend());
    sort(listsB.begin(), listsB.end());
    nenso();
    
    for (auto i: listsA){
        if (i.fi != -1 and i.se >= k){
            ans++;
        }
    }
    for (auto i: listsB){
        if (i.fi != -1 and i.se >= k){
            ans++;
        }
    }
    solve();
    cout << ans;
    return 0;
}