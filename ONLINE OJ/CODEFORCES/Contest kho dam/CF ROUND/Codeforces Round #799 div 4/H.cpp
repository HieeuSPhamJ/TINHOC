#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 2 * 1e5 + 10;


int a[maxN];
ii b[maxN];
ii seg[maxN * 4];


bool cmp(ii x, ii y){
    return x.s < y.s;
}

ii tmax(ii x, ii y){
    if (x.f <= y.f){
        return y;
    }
    return x;
}

void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i].f += val;
        return;
    }

    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);

    seg[i] = tmax(seg[2 * i + 1], seg[2 * i]);
    
}


ii get(int i, int left, int right, int _left, int _right){
        if (_right < left or right < _left){
            return {0,0};
        }
        if (_left <= left and right <= _right){
            return seg[i];
        }

        int mid = (left + right) / 2;

        return tmax(get(2 * i, left, mid, _left, _right), get(2 * i + 1, mid + 1, right, _left, _right));
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        memset(seg, 0, sizeof(seg));
        int n;
        cin >> n;
        b[0] = {0, 0};
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
        }

        for (int i = 1; i <= n; i++){
            update(1, 1, n, a[i], 1);
        }

        int left = 1;
        int right = n;
        int price = maxNum;

        


        cout << endl;
    }
    

    return 0;
}


