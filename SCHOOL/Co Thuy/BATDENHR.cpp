#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector <int> lists;
map <int,int> conv;

bool getBit(int mask, int i){
    return (mask & (1 << i));
}

int onBit(int mask, int i){
    return mask | (1 << i);
}

int offBit(int mask, int i){
    return (mask xor (1 << i));
}

int countBits(int mask){
    int count = 0;
    while (mask){
        count += (mask & 1);
        mask >>= 1;
    }
    return count;
}

int lcm(int x, int y){
    int gcd = __gcd(x,y);
    return (x * y / gcd);
}

int daucatmoi[1 << 20];

int cal(int x){
    int ans = 0;
    int N = (int)(lists.size());
    for (int mask = 1; mask < (1 << N); mask++){
        int y = daucatmoi[mask];
        int temp = x / y;
        if (__builtin_popcount(mask) % 2 == 0){
            temp = -temp;
        }
        ans += temp;
    }
    return ans;
}

signed main(){
    freopen("BATDENHR.INP", "r", stdin);
    freopen("BATDENHR.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        // cout << "TEST" << endl;
        lists.clear();
        for (int i = 1; i <= 40; i++){
            char inp;
            cin >> inp;
            if (inp == '1'){
                lists.push_back(i);
                conv[lists.size() - 1] = i;
            }
        }
        for (int mask = 1; mask < (1 << (int)(lists.size())); mask++){
            int y = 1;
            for (int j = 0; j <= (int)(lists.size()); j++){
                if (getBit(mask, j)){
                    y = lcm(y,conv[j]);
                }
            }
            daucatmoi[mask] = y;

        }
        int k;
        cin >> k;
        // for (auto i: lists){
        //     cout << i << " ";
        // }
        // cout << endl;

        // cout << 8 << ": " << cal(15) << endl;
        int left = 1;
        int right = 1e18;
        int ans = 0;
        while(left <= right){
            int x = (left + right) / 2;
            int cnt = cal(x);
            // cout << left << " " << x << " " << right << endl;
            // cout << cnt << " ";
            int check = 0;
            for (auto i: lists){
                if (x % i == 0 and cnt == k){
                    check = 1;
                    break;
                }
            }
            // cout << check << endl;
            if (check == 1){
                ans = x;
                break;
            }
            if (cnt < k){
                ans = x;
                left = x + 1; 
            }
            else{
                right = x - 1;
            }

        }

        cout << ans << endl;

    }
    return 0;
}