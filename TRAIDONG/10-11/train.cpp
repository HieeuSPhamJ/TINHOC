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

int N = maxN;
int seg[maxN * 4];
multiset <int> store;

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

int sizeTrain(){
    return seg[1];
}

int getGreater(int val){
    return get(1,1,N,val + 1, N);
}

void insertVal(int val){
    update(1,1,N,val,1);
    store.insert(val);
}

int getLast(){
    auto it = store.end();
    it--;
    return *it;
}

void removeVal(int val){
    update(1,1,N,val,-1);
    store.erase(store.find(val));
}


vector <ii> lists;

void nenso(){
    set <int> temp;
    for (auto i: lists){
        temp.insert(i.fi);
        temp.insert(i.se);
    }
    int cnt = 1;
    map <int,int> conv;
    for (auto i: temp){
        conv[i] = cnt;
        cnt++;
    }
    for (int i = 0; i < lists.size(); i++){
        lists[i].fi = conv[lists[i].fi];
        lists[i].se = conv[lists[i].se];
        
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, cap, trash;
    cin >> n >> cap >> trash;
    // cout << n << " " << cap << endl;
    while(n--){
        int a, b;
        cin >> a >> b;
        lists.push_back({a,b});
    }
    sort(lists.begin(), lists.end());
    nenso();
    for (auto i: lists){
        int a = i.fi;
        int b = i.se;
        // cout << "With: " << a << " " << b << endl;
        if (sizeTrain() == 0){
            // cout << "Empty" << endl;
            insertVal(b);
            continue;
        }
        int num = getGreater(a);
        // cout << num << " ";
        if (num >= cap){
            if (getGreater(b) <= 0){
                // cout << "No change" << endl;
                continue;
            }
            int last = getLast();
            if (last > b){
                // cout << "Change" << endl;
                removeVal(last);
                insertVal(b);
            }
        }
        else{
            // cout << "Push" << endl;
            insertVal(b);
        }
    }

    cout << sizeTrain();

    return 0;
}