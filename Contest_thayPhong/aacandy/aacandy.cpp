// #include <bits/stdc++.h>
// using namespace std;
// 
// 
// 
// int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
	// int n; cin>>n;
	// int ans = 0;
	// for (int i=1;i*i<=n;i++){
		// int check = n-(i*i)+i;
		// // cout<<'#'<<i<<' '<<check<<endl;
		// if (!(check%i) and check/i%2){
			// ans++;
		// }
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