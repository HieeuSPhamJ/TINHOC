#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int maxVal = 1e6 + 10;

struct dataType{
    int left;
    int right;
    int pos;
    dataType(int a, int b, int c){
        left = a;
        right = b;
        pos = c;
    }
    
};

int sq;
int a[maxN];
int check[maxVal];
vector <dataType> query;
vector <ii> Ans;

bool cmp(dataType x, dataType y){
    if (x.left / sq != y.left / sq){
        return x.left < y.left;
    }
    return x.right < y.right;
}

int cal(int index){
    return check[a[index]] * check[a[index]] * a[index];
}

void printCheck(){
    for (int i = 1; i <= 3; i++){
        cout << i << ":" << check[i] << " ";
    }
    cout << endl;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sq = sqrt(n);

    for (int i = 1; i <= test; i++){
        int l, r;
        cin >> l >> r;
        query.push_back({l,r,i});
    }

    sort(query.begin(), query.end(), cmp);

    int ans = 0;
    int left = 1;
    int right = 1;

    check[a[1]]++;
    ans += cal(1);
    // cout << ans << endl;
    // printCheck();


    for (auto i: query){
        int _left = i.left;
        int _right = i.right;
        // cout << _left << ' ' << _right << endl;

        while(right < _right){
            // printCheck();
            right++;
            ans -= cal(right);
            check[a[right]]++;
            ans += cal(right);
            // printCheck();
            // cout << ans << endl;
            // cout << left << '-' << right << endl;

        }

        while(right > _right){
            ans -= cal(right);
            // printCheck();
            check[a[right]]--;
            ans += cal(right);
            right--;
            // printCheck();
            // cout << ans << endl;
            // cout << left << '-' << right << endl;

        }

        while(left < _left){
            ans -= cal(left);
            // printCheck();
            check[a[left]]--;
            ans += cal(left);
            left++;
            // printCheck();
            // cout << ans << endl;
            // cout << left << '-' << right << endl;

        }

        while(left > _left){
            left--;
            ans -= cal(left);
            // printCheck();
            check[a[left]]++;
            ans += cal(left);
            // printCheck();
            // cout << ans << endl;
            // cout << left << '-' << right << endl;

        }
        Ans.push_back({i.pos, ans});
        // cout << ans << endl;
    }

    sort(Ans.begin(), Ans.end());
    for (auto i: Ans){
        cout <<  i.s << endl;
    }




    return 0;
}