#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
#define vec vector <ll>
using namespace std;

ll a[15];
ll ans = 0;

bool cmp(ll a, ll b){
    return a > b;
}

void print(vec lists){
    sort(lists.begin(), lists.end(), cmp);
    for (auto i: lists){
        cout << i << " ";
    }
    cout << endl;
}

void backtracking(int index, vec tempList){
        // print(tempList);
    if (index > 4){
        sort(tempList.begin(), tempList.end(), cmp);
        ans = max(ans, tempList[1] * tempList[3]);
        return;
    }

    int nn = a[index];
    for (int i = 0; i <= nn; i++){
        tempList.push_back(i);
        nn -= i;
        for (int j = 0; j <= nn; j++){
            nn -= j;
            tempList.push_back(j);
            for (int q = 0; q <= nn; q++){
                nn -= q;
                tempList.push_back(q);
                tempList.push_back(nn);
                
                backtracking(index + 1, tempList);
                nn += q;

                tempList.pop_back();
                tempList.pop_back();
            }
            nn += j;
            tempList.pop_back();
        }
        nn += i;
        tempList.pop_back();
        
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    cin >> a[1] >> a[2] >> a[3] >> a[4];

    backtracking(1, {});

    cout << ans;

    return 0;
}