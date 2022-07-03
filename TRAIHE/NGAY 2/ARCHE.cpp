#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e5 + 10;

struct iii{
    int a;
    int b;
    int val;
    iii(int q, int w, int e){
        a = q;
        b = w;
        val = e;
    }
};

int n, m;
vector <iii> constList;
vector <iii> tempList;
int boss[maxN];

void printBoss(){
    for (int i = 1; i <= n; i++){
        cout << boss[i] << ' ';
    }
    cout << endl;
}

int findBoss(int i){
    if (boss[i] == i){
        return i;
    }
    return boss[i] = findBoss(boss[i]);
}

bool cmp(iii a, iii b){
    return a.val > b.val;
}

bool check(int power){
    for (int i = 1; i <= n; i++){
        boss[i] = i;
    }
    
    for (auto i: tempList){
        // cout << i.a << ' ' << i.b << ' ' << i.val << endl;
        if (i.val <= power){
            break;
        }
        int u = findBoss(i.a);
        int v = findBoss(i.b);
        if (u == v){
            continue;
        }        
        boss[u] = v;
    }

    // printBoss();

    for (auto i: constList){
        int u = findBoss(i.a);
        int v = findBoss(i.b);
        if (u == v){
            return 0;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        iii temp(a, b, c);

        if (c == -1){
            constList.push_back(temp);
        }
        else{
            tempList.push_back(temp);
        }
    }

    sort(tempList.begin(), tempList.end(), cmp);

    int left = 0;
    int right = 1e9;
    int mid = 0;

    int ans = 0;
    
    while (left <= right){
        mid = (left + right) / 2;
        // cout << left << ' ' << mid << ' ' << right << endl;
        if (check(mid)){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    // cout << endl;
    
    if (check(ans)){
        cout << ans;
    }
    else{
        cout << -1; 
    }

    // cout << check(1);
    
    return 0;
}