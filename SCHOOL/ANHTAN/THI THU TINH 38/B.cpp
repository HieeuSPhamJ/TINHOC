#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

unordered_map <int, int> countMapA;
unordered_map <int, int> countMapB;
unordered_map <int, int> countMapC;
vector <int> A;
vector <int> B;
vector <int> C;

int n, test;

int calL(vector <int> lists, int a, int b){
    int left = 0;
    int right = (int)lists.size() - 1;
    int ans = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (lists[mid] < a){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ans + 1;
}

int calR(vector <int> lists, int a, int b){
    int left = a;
    int right = (int)lists.size() - 1;
    int ans = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (lists[mid] < b){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ans + 1;
}

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

void Type2(){
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (A[i] == B[j]){
                // cout << i << " " <<  j << " ";
                // cout << A[i] << " " << B[i] << " ";
                cout << A[i] << endl;
                int l = calL(C,1,A[i]);
                int r = calR(C,1,A[i]);
                cout << l << " " << r << endl;
                // ans += (r - l) + 1;
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
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());


    for (auto i: A){
        cout << i << " ";
    }
    cout << endl;
    for (auto i: B){
        cout << i << " ";
    }
    cout << endl;
    for (auto i: C){
        cout << i << " ";
    }
    cout << endl;
    
    if (test == 1){
        Type1();
        cout << endl;
    }
    else if (test == 2){
        // Type2();
    }

    
    cout << calL(C,2-1,30) << endl;

    return 0;
}