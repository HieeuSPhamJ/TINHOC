#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxB = 20;
const int maxN = 3 * 1e5 + 10;

struct Node{
    int child[2] = {0};
};
struct trie{
    vector<Node> t = {Node()};
    void add(int x){
        int p = 0;
        for(int i=19;i>=0;i--){
            int bit = (x>>i)&1;
            if (!t[p].child[bit]){
                t[p].child[bit] = t.size();
                t.push_back(Node());
            }
            p = t[p].child[bit];
        }
    }
    int get(int x){
        int p = 0, ans = 0;
        for(int i=19;i>=0;i--){
            int bit = (x>>i)&1;
            if (t[p].child[bit^1]){
                ans |= (1<<i);
                p = t[p].child[bit^1];
            }
            else p = t[p].child[bit];
        }
        return ans;
    }
};

trie seg[maxN * 4];

void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i].add(val);
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);

    seg[i].add(val);
}

int get(int i, int left, int right, int _left, int _right, int val){
    if (right < _left or _right < left){
        return 0;
    }
    if (_left <= left and right <= _right){
        int r = seg[i].get(val);
        // cout << left << " " << right << " " << r << " "  << (r xor val) << endl;
        return r;
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right, val);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right, val);

    return max(t1,t2);
}


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
        update(1,1,n,i,x);
    }
    int test;
    cin >> test;
    while(test--){
        int l,r,x;
        cin >> l >> r >> x;
        cout << get(1,1,n,l,r,x) << endl;
    }
    return 0;
}