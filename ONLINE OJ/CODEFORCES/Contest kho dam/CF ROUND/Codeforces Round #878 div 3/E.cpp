#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;
const int inf = 1e18;

int n;

struct segmenttree2d{
    int seg[4 * maxN];
    int re[maxN];
    void init(){
        for (int i = 1; i <= 4 * n; i++){
            seg[i] = -inf;
        }
        for (int i = 1; i <= n; i++){
            re[i] = -inf;
        }
    }
    void update(int i, int l, int r, int id, int v){
        if (id < l or r < id){
            return;
        }
        if (l == r){
            seg[i] = v;
            re[id] = v;
            return;
        }

        int mid = (l + r) / 2;

        update(2 * i, l, mid, id, v);
        update(2 * i + 1, mid + 1, r, id, v);

        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }
    int get(int i, int l, int r, int L, int R){
        if (R < l or r < L){
            return -inf;
        }
        if (L <= l and r <= R){
            return seg[i];
        }

        int mid = (l + r) / 2;

        return max(get(2 * i, l, mid, L, R), get(2 * i + 1, mid + 1, r, L, R));
    }
} seg;

void print(){
    for (int i = 1; i <= n; i++){
        cout << seg.get(1,1,n,i,i) << ' ';
    }
    cout << endl;
}

int CNTERROR = 0;
int cec[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        string s[3];
        cin >> s[1] >> s[2];
        CNTERROR = 0;
        n = s[1].length();
        s[1] = " " + s[1];
        s[2] = " " + s[2];
        int t, q;
        cin >> t >> q;
        seg.init();
        for (int i = 1; i <= n; i++){
            if (s[1][i] != s[2][i]){
                seg.update(1,1,n,i,1);
                CNTERROR++;
            }
            else{
                seg.update(1,1,n,i,0);
            }
        }
        for (int i = 0; i <= q + 1; i++){
            cec[i] = 0;
        }
        queue <ii> qu;
        for (int time = 1; time <= q; time++){
            // cout << "With: " << time << " " << CNTERROR << endl;
            while(qu.size() and qu.front().fi == time){
                // cout << qu.front().fi << " " << qu.front().se << endl;
                if (s[1][qu.front().se] != s[2][qu.front().se]){
                    seg.update(1,1,n,qu.front().se,1);
                }
                else{
                    seg.update(1,1,n,qu.front().se,0);
                }
                qu.pop();
            }
            CNTERROR += cec[time];

            int type;
            cin >> type;
            if (type == 3){
                // cout << seg.get(1,1,n,1,n) << " ";
                if (CNTERROR == 0){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
            else if (type == 1){
                int x;
                cin >> x;
                qu.push({time + t, x});
                seg.update(1,1,n,x,-1);
                if(s[1][x]!=s[2][x]){
                    cec[min(time+t,q+1)] += 1 + cec[min(time+t,q+1)] - cec[min(time+t,q+1)];
                    CNTERROR--;
                }
            }
            else{
                int t1,i1,t2,i2;
                cin >> t1 >> i1 >> t2 >> i2;
                int ib1 = seg.get(1,1,n,i1,i1);
                int ib2 = seg.get(1,1,n,i2,i2);
                if (ib1 != -1){
                    if (s[t1][i1] != s[t2][i1]){
                        seg.update(1,1,n,i1,1);
                    }
                    else{
                        seg.update(1,1,n,i1,0);
                    }
                }
                if (ib2 != -1){
                    if (s[t1][i2] != s[t2][i2]){
                        seg.update(1,1,n,i2,1);
                    }
                    else{
                        seg.update(1,1,n,i2,0);
                    }
                }


                
               if(s[t1][i1]!=s[((t1 - 1 ^1) + 1)][i1]) CNTERROR--;
               if(s[t2][i2]!=s[((t2 - 1 ^1) + 1)][i2]) CNTERROR--;
               swap(s[t1][i1],s[t2][i2]);
               if(s[t1][i1]!=s[((t1 - 1^1) + 1)][i1]) CNTERROR++;
               if(s[t2][i2]!=s[((t2 - 1^1) + 1)][i2]) CNTERROR++;
                // cout << s[1] << " " << t1 << ' ' << i2 << endl;
                // cout << s[2] << " " << t2 << ' ' << i2 << endl;
            }
            // print();
        }
        

    }
    return 0;
}
/*
0 0 0 0 1 1 1 0 1 0
c o d e f o r c e s
c o d e b l o c k s
*/