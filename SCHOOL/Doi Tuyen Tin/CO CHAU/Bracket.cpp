#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int maxN = 1e6 + 10;

int countMax[maxN];
int a[maxN];
stack <int> myStack;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++){
        a[i + 1] = (s[i] == ')');
    }
    for (int i = 1; i <= n; i++){
        cout << a[i];
    }

    int tempLen = 0;

    for (int i = 1; i <= n; i++){
        if (myStack.empty() = )
    }
    return 0;
}