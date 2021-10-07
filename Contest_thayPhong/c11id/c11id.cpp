// #include <bits/stdc++.h>
// using namespace std;
// 
// const int ma = 1e9;
// int a[100010];
// 
// int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    // int n; cin>>n;
    // for (int i=1;i<=n;i++) cin>>a[i];
    // long long ans = 1;
    // sort(a+1, a+n+1);
    // for (int i=1;i<=n;i++){
    	// ans = ((ans%ma)*(a[i]-i+1)%ma)%ma;
    // }
    // cout<<ans;
    // return 0;
// }


#include <bits/stdc++.h>
using namespace std;
long n,s=0;
int kq=0;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	int i=1;
	while(s<n){
		s=s+2*(i-1);
		if((n-s)/i==0 && ((n-s)/i)%2!=0){
			kq++;
			cout<<(n-s)/i<<endl;
		}
		i++;
	}
	cout<<kq;
	return 0;
}