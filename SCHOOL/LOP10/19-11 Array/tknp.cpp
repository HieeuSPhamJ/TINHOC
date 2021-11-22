#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6+10;

pair<long long,int> a[maxN];
int n,t;

bool cmp(pair<long long,int> a,pair<long long,int> b){
    return a.first<=b.first;
}

int binarySearch() {
    int left=1;
    int right=n;
    while (left<=right){
        int mid=left+(right-left)/2;
        if (a[mid].first==t){
            return a[mid].second;   
        }    	
        else if (a[mid].first<t){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}    	

int main(){
    cin>>n>>t;
    for (int i=1;i<=n;i++){
        int inp;
        cin>>inp;
        a[i]=make_pair(inp,i);
    }
    sort(a+1,a+n+1,cmp);
    cout<<binarySearch();
    return 0;
}