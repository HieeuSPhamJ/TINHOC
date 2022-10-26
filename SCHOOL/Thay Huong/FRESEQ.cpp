#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <int,ii>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;

int n, q;
int a[maxN];
int cnt = 1;
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

bool cmp(iii a, iii b){
    int s = sqrt(n);
    if (a.se.fi / s == b.se.fi / s){
        return a.se.se / s < b.se.se / s;
    }
    return a.se.fi / s < b.se.fi / s;
}

void nenso(){
    set <int> count;
    map <int, int> cnv;
    for (int i = 1; i <= n; i++){
        count.insert(a[i]);
    }
    
    for (auto i: count){
        cnv[i] = cnt;
        cnt++;
    }
    for (int i = 1; i <= n; i++){
        a[i] = cnv[a[i]];
    }
}

struct node{
    int left = 0, right = 0, llen = 0, rlen = 0, val = 0;
};

void print(node i){
    cout << i.left << " " << i.llen << " " << i.right << " " << i.rlen << " " << i.val << endl;
}

node seg3[maxN * 4];

void build(int i, int left, int right){
    if (left == right){
        seg3[i] = {a[left], a[left], 1, 1, 1};
        // cout << left << " " << right << endl;
        // print(seg3[i]);
        // cout << "base" << endl;
        return;
    }
    int mid = (left + right) / 2;
    build(2 * i, left, mid);
    build(2 * i + 1, mid + 1, right);
    node t1 = seg3[2 * i];
    node t2 = seg3[2 * i + 1];
    // cout << left << " " << right << endl;
    // print(t1);
    // print(t2);
    seg3[i].val = max(t1.val, t2.val);
    seg3[i].left = t1.left;
    seg3[i].llen = t1.llen;
    seg3[i].right = t2.right;
    seg3[i].rlen = t2.rlen;
    // print(seg3[i]);
    if (t1.right == t2.left){
        seg3[i].val = max(seg3[i].val, t1.rlen + t2.llen);
    }
    if (seg3[i].left == t2.left){
        seg3[i].llen += t2.llen;
    }

    if (seg3[i].right == t1.right){
        seg3[i].rlen += t1.rlen;
    }
    
    // print(seg3[i]);
}

node get3(int i, int left, int right, int _left, int _right){
    // cout << left << " " << right << endl;
    if (right < _left or _right < left){
        return {0,0,0,0,0};
    }
    if (_left <= left and right <= _right){
        return seg3[i];
    }

    node now = {0,0,0,0,0};
    int mid = (left + right) / 2;
    node t1 = get3(2 * i, left, mid, _left, _right);
    node t2 = get3(2 * i + 1, mid + 1, right, _left, _right);
    now.val = max(t1.val, t2.val);
    now.left = t1.left;
    now.llen = t1.llen;
    now.right = t2.right;
    now.rlen = t2.rlen;
    // print(now);
    if (t1.right == t2.left){
        now.val = max(now.val, t1.rlen + t2.llen);
    }
    if (now.left == t2.left){
        now.llen += t2.llen;
    }

    if (now.right == t1.right){
        now.rlen += t1.rlen;
    }
    return now;
}

void sub3(){
    build(1,1,n);
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << get3(1,1,n,a,b).val << endl;
    }
}

signed main(){
    freopen("FRESEQ.INP", "r", stdin);
    freopen("FRESEQ.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    nenso();
    if (n > 1000){
        // cout << "SUB 3:" << endl;
        sub3();
        return 0;
    }
    vector <iii> lists;
    for (int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        lists.push_back({i,{a,b}});
    }

    sort(lists.begin(), lists.end(), cmp);

    vector <ii> ans;

    int left = 1;
    int right = 1;
    update(1,1,n,a[1],1);

    for (auto query: lists){
        int LEFT = query.se.fi;
        int RIGHT = query.se.se;
        // cout << LEFT << " " << RIGHT << endl;
        while(left > LEFT){
            left--;
            update(1,1,n,a[left],1);
        }
        while(left < LEFT){
            update(1,1,n,a[left],-1);
            left++;
        }
        while(right < RIGHT){
            right++;
            update(1,1,n,a[right],1);
        }
        while(right > RIGHT){
            update(1,1,n,a[right], -1);
            right--;
        }
        // for (int i = 1; i <= n; i++){
        //     cout << get(1,1,n,i,i) << " ";
        // }
        // cout << endl;
        int t = get(1,1,n,1,n);
        ans.push_back({query.fi, t});
    }

    sort(ans.begin(), ans.end());

    for (auto i: ans){
        cout << i.se << endl;
    }

    return 0;
}