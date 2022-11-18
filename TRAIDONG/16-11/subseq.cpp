#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, k;
int a[maxN];
int prefix[maxN];
int allPrefix[maxN];

int sum(int l, int r){
    return prefix[r + 1] - prefix[l];
}

int allSum(int l, int r){
    l++;
    r++;
    // cout << "With: " << l << " " << r << endl;
    return allPrefix[r] - allPrefix[l - 1] - prefix[l - 1] * (r - l + 1);
}

void sub1(){
    deque <int> A;
    for (int i = 1; i <= n; i++){
        A.push_back(a[i]);
    }
    for (int t = 1; t <= n; t++){
        int cnt = 0;
        int s = 0;
        for (int i = 0; i < n; i++){
            int ans = 0;
            for (int j = i; j < n; j++){
                ans += A[j];
                if (ans <= k){
                    s += ans;
                    cnt++;
                }
                else{
                    break;
                }
            } 
        }
        A.push_back(A.front());
        A.pop_front();
        cout << s << " " << cnt << endl;
    }
}

void sub2(){
    deque <int> A;
    for (int i = 1; i <= n; i++){
        A.push_back(a[i]);
    }
    for (int t = 1; t <= n; t++){
        for (int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + A[i - 1];
            allPrefix[i] = allPrefix[i - 1] + prefix[i];
        }
        // for (auto i: A){
        //     cout << i << " ";
        // }
        // cout << endl;
        // for (int i = 1; i <= n; i++){
        //     cout << prefix[i] << " ";
        // }
        // cout << endl;
        // for (int i = 1; i <= n; i++){
        //     cout << allPrefix[i] << " ";
        // }
        // cout << endl;


        // cout << allSum(0,1) << endl;
        // cout << allSum(1,2) << endl;
        // cout << allSum(2,2) << endl;
        
        int cnt = 0;
        int s = 0;
        int left = 0;
        int right = 0;

        while(right < n){
            while (sum(left, right) <= k and right < n){
                right++;
            }
            right--;    
            // cout << left + 1 << " " << right + 1 << endl;
            cnt += (right - left) + 1;
            s += allSum(left, right);
            // cout << allSum(left, right) << endl;
            left++;
            if (right < left){
                right = left;
            }
        }

        A.push_back(A.front());
        A.pop_front();
        // cout << "Ans: " << endl;
        cout << s << " " << cnt << endl;
    }
}

void sub3(){

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // if (n <= 500){
    //     sub1();
    //     return 0;
    // }
    // if (n <= 1000){
        sub2();
    //     return 0;
    // }
    // sub3();
    return 0;
}