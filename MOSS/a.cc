#include<bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n , k , a[N] , cnt[N] , Pre[N] , vt[N] , pre[N][3];

int st[4 * N];

void update(int id , int l , int r , int u , int v){
    if(u > r || u < l) return;
    if(l == r){
        st[id] += v;
        return;
    }
    int mid = l + r >> 1;
    update(id * 2 , l , mid , u , v);
    update(id * 2 + 1 , mid + 1 , r , u , v);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id , int l , int r , int u , int v){
    if(u > r || v < l) return 0;
    if(u <= l && v >= r){
        return st[id];
    }
    int mid = l + r >> 1;
    return get(id * 2 , l , mid , u, v) + get(id * 2 + 1,  mid + 1 , r , u , v);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    if(n <= 3000 && k <= 3000){
        int res = 0;
        for(int i = 1 ; i <= n ; i++){
            set<pair<int , int>> s;
            for(int j = i ; j <= n ; j++){
                if(cnt[a[j]] == 0){
                    cnt[a[j]]++;
                    s . insert({cnt[a[j]] , a[j]});
                }
                else{
                    auto it = s . find({cnt[a[j]] , a[j]});
                    s . erase(it);
                    cnt[a[j]]++;
                    s . insert({cnt[a[j]] , a[j]});
                }
                auto it = s . begin();
                int x = (*it) . first;
                it = (s . end());
                it--;
                int y = (*it) . first;
                if(x == k && y == k) res++;
            }
            for(int j = 1 ; j <= n ; j++) cnt[j] = 0;
        }
        cout << res;
    }
    else if(k == 1){
        long long res = 0;
        for(int i = 1 ; i <= n ; i++){
            update(1 , 1 , n , Pre[a[i]] , -1);
            update(1 , 1 , n , i , 1);
            Pre[a[i]] = i;
            int l = 1 , r = i;
            int j = i;
            while(l <= r){
                int mid = l + r >> 1;
                if(get(1 , 1 , n , mid , i) == (i - mid + 1)){
                    r = mid - 1;
                    j = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            res += (i - j + 1);
        }
        cout << res;
    }
    else{
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= 2 ; j++){
                pre[i][j] = pre[i - 1][j] + (a[i] == j ? 1 : 0);
            }
        }
        for(int i = 1 ; i <= n ; i++){
            int j = a[i];
            int l = 1 , r = i;
            int res = i;
            if(pre[i][j] < k) continue;
            while(l <= r){
                int mid = l + r >> 1;
                if(pre[i][j] - pre[mid - 1][j] >= k){
                    res = mid;
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            vt[i] = res;
        }
        int res = 0;
        for(int i = 1 ; i <= n ; i++){
            int j = vt[i];
            if(vt[i] == 0) continue;
            if(i - j + 1 == k){
              //  cout << i << ' ' << j << "\n";
                res++;
            }
            int x = (a[i] == 1 ? 2 : 1);
            int l = 1 , r = i;
            while(l <= r){
                int mid = l + r >> 1;
                if(pre[i][x] - pre[mid - 1][x] >= k){
                    l = mid + 1;
                    j = mid;
                }
                else{
                    r = mid - 1;
                }
            }
            if(i - j + 1 == 2 * k && pre[i][a[i]] - pre[j - 1][a[i]] == k){
                //cout << i << ' ' << j << "\n";
                res++;
            }
            if(j > vt[i] && i - vt[i] + 1 == 2 * k ){
                res++;
            }


        }
        cout << res;
    }

    return 0;
}
/*┌─────────────────────────────────────────────────────────────────────────┐ 
  │ Just believe in yourself and try your best. Flower will pray for you... │ 
  └─────────────────────────────────────────────────────────────────────────┘*/
