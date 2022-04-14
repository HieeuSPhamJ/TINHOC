#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];
int countBigger[maxN];
int countSmaller[maxN];
int diff[maxN];
map <int, int> leftCount;
map <int, int> rightCount;
vector <int> leftVec;
vector <int> rightVec;
map <int, int> tempCount;
int main(){
    freopen("trungvi.INP", "r", stdin);
    freopen("trungvi.OUT", "w", stdout);
    int n, m;
    cin >> n >> m;
    int index;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == m){
            index = i;
        }
    }
    countBigger[index] = 0;
    countSmaller[index] = 0;
    for (int i = index; i >= 1; i--){
        countBigger[i] = countBigger[i + 1];
        countSmaller[i] = countSmaller[i + 1];
        if (a[i] < m){
            countSmaller[i]++;
        }
        if (a[i] > m){
            countBigger[i]++;
        }
        diff[i] = countSmaller[i] - countBigger[i];
    }
    for (int i = index + 1; i <= n; i++){
        countBigger[i] = countBigger[i - 1];
        countSmaller[i] = countSmaller[i - 1];
        if (a[i] < m){
            countSmaller[i]++;
        }
        if (a[i] > m){
            countBigger[i]++;
        }
        diff[i] = countSmaller[i] - countBigger[i];
    }
    // cout << index;
    // sort(diff + 1, diff + index);
    // sort(diff + 1 + index, diff + 1 + n);
    // for (int i = 1; i <= n; i++){
    //     cout << diff[i] << ' ';
    // }
    // cout << endl;
    for (int i = 1; i <= index; i++){
        leftCount[diff[i]]++;
        leftVec.push_back(diff[i]);
    }
    for (int i = index; i <= n; i++){
        rightCount[diff[i]]++;
        rightVec.push_back(diff[i]);
    }
    if (leftVec.size() > rightVec.size()){
        swap(leftVec, rightVec);
        swap(leftCount, rightCount);
    }
    // sort(rightCount.begin(), rightCount.end());
    long long count = 1;
    for (int i = 0; i < (int)leftVec.size() - 1; i++){
        count+= rightCount[-leftVec[i]];
    }

    cout << count;

    return 0;
}
