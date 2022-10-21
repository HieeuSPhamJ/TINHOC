#include<bits/stdc++.h>
#define ii pair <double,double>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

char T;
int n;
vector <ii> lists;
ii a[maxN];
int x[maxN];

int cw(ii a, ii b, ii c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se) > 0;
}

bool cal1(int i, ii p){
    return cw(lists[(i) % n], lists[(i + 1) % n],p);
}

bool cal2(int i, ii p){
    int step = n / 2;
    return cw(lists[(i) % n], lists[(i + 1) % n],p) and cw(lists[(i + step) % n], lists[(i + 1 + step) % n],p);
}

void print(ii node){
    cout << node.fi << " " << node.se << endl;
}

signed main(){
    freopen("nhap.txt", "r", stdin);
    freopen("nhap.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T >> n;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        lists.push_back({x,y});
    }

    int test;
    cin >> test;
    for (int i = 1; i <= test; i++){
        cin >> a[i].fi >> a[i].se;
    }

    int step = n / 2;

    for (int t = 1; t <= test; t++){
        x[t] = x[max(t - 1, 0ll)];
        if (T == '1'){
            a[t].fi = ((int)(a[t].fi) xor (int)(x[t - 1] * x[t - 1] * x[t - 1]));
            a[t].se = ((int)(a[t].se) xor (int)(x[t - 1] * x[t - 1] * x[t - 1]));
        }
        ii p = a[t];
        bool check = 0;
        if (cal1(0,p)){
            int left = 0;
            int right = n / 2;
            int id = 0;
            while(left <= right){
                int mid = (left + right) / 2;
                if (cal1(mid,p)){
                    left = mid + 1;
                    id = mid;
                }
                else{
                    right = mid - 1;
                }
            }
            if (cal2(id,p)){
                check = 1;
            }
        }
        else{
            int left = 0;
            int right = n / 2;
            int id = 0;
            while(left <= right){
                int mid = (left + right) / 2;
                if (cal1(mid,p)){
                    right = mid - 1;
                    id = mid;
                }
                else{
                    left = mid + 1;
                }
            }
            if (cal2(id,p)){
                check = 1;
            }
        }
        if (check){
            x[t]++;
            cout << "DA";
        }
        else{
            cout << "NE";
        }
        cout << endl;
    }   
    
    return 0;
}