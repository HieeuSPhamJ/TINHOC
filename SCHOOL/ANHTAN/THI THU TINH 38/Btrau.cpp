#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

bool check(int a, int b, int c){
    if (a + b <= c or a + c <= b or b + c <= a){
        return 0;
    }
    return 1;
}

int n, test;
unordered_map <int, int> countMapA;
unordered_map <int, int> countMapB;
unordered_map <int, int> countMapC;
vector <int> A;
vector <int> B;
vector <int> C;


void Type1(){
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (A[i] == B[j]){
                // cout << i << " " <<  j << " ";
                // cout << A[i] << " " << B[i] << " ";
                ans += countMapC[A[i]];
                // cout <<  countMap[A[i]] << endl;                   
            }
        }
    }
    cout << ans;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> test;    
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        A.push_back(inp);
        countMapA[inp]++;
    }
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        B.push_back(inp);
        countMapB[inp]++;
    }
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        C.push_back(inp);
        countMapC[inp]++;
    }

    if (test == 1){
        Type1();
    }
    else if (test == 2){
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n; k++){
                    if ((A[i] == B[j] or A[i] == C[k] or B[j] == C[k]) and check(A[i],B[j],C[k])){
                        ans++;
                    }
                }
            }
        }
        cout << ans;
    }
    else{
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n; k++){
                    if (check(A[i],B[j],C[k])){
                        ans++;
                    }
                }
            }
        }
        cout << ans;
    }

    return 0;
}