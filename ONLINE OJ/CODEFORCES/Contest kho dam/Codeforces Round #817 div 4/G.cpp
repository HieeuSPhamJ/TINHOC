#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];
set <int> lists[3];

void create(int type, int n){
    // a[1 + type] = n;
    // lists[type].insert(n);
    // cout << n << " ";
    int m = n;
    for (int i = 0; i <= 18; i+=2){
        m = (m xor (1 << i));
    }
    // a[3 + type] = m;
    // lists[type].insert(m);
    // cout << m << " ";
    m = n;
    for (int i = 1; i <= 18; i+=2){
        m = (m xor (1 << i));
    }
    // a[5 + type] = m;
    // lists[type].insert(m);
    // cout << m << endl;
    for (int i = 0; i < (1 << 18); i++){
        int j = i;
        if (type == 1){
            j = (i xor (1 << 19));
        }
        lists[type].insert(j);
        // cout << j << endl;
    }
}

void init(){
    create(0,((1 << 19) - 1));
    create(1,((1 << 20) - 1));
    int j = 7;
    a[1] = 2097151;
    a[2] = 4194303;
    a[3] = 1747626;
    a[4] = 3844778;
    a[5] = 1922389;
    a[6] = 4019541;
    for (auto i: lists[0]){
        a[j] = i;
        j += 2;
        if (j >= maxN){
            break;
        }
    }
    j = 8;
    for (auto i: lists[1]){
        a[j] = i;
        j += 2;
        if (j >= maxN){
            break;
        }
    }
    // cout << lists[0].size() << " " << lists[1].size() << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        if (n == 3){
            cout << "2 1 3" << endl;
            continue;
        }
        if (n == 4){
            cout << "2 1 3 0" << endl;
            continue;
        }
        if (n == 5){
            cout << "2 0 4 5 3" << endl;
            continue;
        }
        for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
0111111111111111111111
0010101010101010101010
0101010101010101010101

1111111111111111111111
1010101010101010101010
1101010101010101010101


2097151 4194303 1747626 3844778 1922389 4019541

4194303 xor 3844778 xor 4019541
*/