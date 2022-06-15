#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
#define endl "\n"
using namespace std;

const int maxN = 1e6 + 10;
const int inf = 1e18;

struct dataType{
    int l;
    int r;
    int val;

    dataType(int a, int b, int v){
        l = a;
        r = b;
        val = v;
    }
};

int n, m;
int seg[maxN * 4];
int lazy[maxN * 4];

vector <dataType> listSeg;

bool cmp(dataType a, dataType b){
    return a.val < b.val;
}

void lazz(int i){
    int val = lazy[i];

    seg[2 * i] += val;
    seg[2 * i + 1] += val;
    lazy[2 * i] += val;
    lazy[2 * i + 1] += val;

    lazy[i] = 0;
}

void printTree(){
    // cout << n << endl;
    int count = 0;
    int por = 1;
    for (int i = 1; i <= 4 * m; i++){
        cout << "[" << seg[i] << ", " << lazy[i] << "] ";
        count++;
        if (count == por){
            por *= 2;
            count = 0;
            cout << endl;
        }
    }
    cout << endl;
}

void update(int i, int left, int right, int _left, int _right, int val){
    if (_right < left or right < _left){
        return;
    }
    if (_left <= left and right <= _right){
        lazy[i] += val;
        seg[i] += val;
        return;
    }

    lazz(i);
    
    int mid = (left + right) / 2;

    update(2 * i, left, mid, _left, _right, val);
    update(2 * i + 1, mid + 1, right, _left, _right, val);

    seg[i] = min(seg[2 * i + 1], seg[2 * i]);
    
}


int get(int i, int left, int right, int _left, int _right){
        if (_right < left or right < _left){
            return 0;
        }
        // if (left == right){
        //     cout << left << ' ' << seg[i] << ' ' << _left << endl;
        // }
        if (_left <= left and right <= _right){
            // cout << "!" << left << ' ' << seg[i] << ' ' << _left << endl;
            return seg[i];
        }

        lazz(i);

        int mid = (left + right) / 2;

        int temp = min(get(2 * i, left, mid, _left, _right), get(2 * i + 1, mid + 1, right, _left, _right));
        
        // cout << temp << ' ' << left << ' ' << right << ' ' << _left << endl;

        return temp;
}


bool check(int index){
    dataType prop = listSeg[index];
    // cout << prop.l << ' ' << prop.r << ' ' << prop.val << endl;
    // printTree();
    

    update(1, 1, m, prop.l, prop.r, -1);

    
    if (seg[1] != 0){
        return 1;
    }

    update(1, 1, m, prop.l, prop.r, 1);
    
    return 0;

}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    m--;
    for (int i = 1; i <= n; i++){
        int a, b, val;
        cin >> a >> b >> val;
        b--;
        dataType temp(a, b, val);
        listSeg.push_back(temp);
        update(1, 1, m, a, b, 1);

    }

    // for (int i = 1; i <= m; i++){
    //     cout << get(1, 1, m, i, i) << ' ';
    //     // int t = get(1, 1, m, i, i);
    // }
    // cout << endl;
    
    // printTree();

    sort(listSeg.begin(), listSeg.end(), cmp);

    // for (auto i: listSeg){
    //     cout << i.l << ' ' << i.r << ' ' << i.val << endl;
    // }

    // cout << "------" << endl;
    
    int level = 0;

    int ans = listSeg[0].val;

    while(check(level)){
        ans = listSeg[level + 1].val;
        level++;
    }

    level = listSeg.size() - 1;

    int tempAns = listSeg[listSeg.size() - 1].val;

    while(check(level)){
        tempAns = listSeg[level - 1].val;
        level--;
    }


    cout << abs(tempAns - ans) << endl;



    
    

    return 0;
}
