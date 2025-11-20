#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		long long n;
		double ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			ans+=1.0*n/(n-i+1);
		}
		cout<<fixed<<setprecision(3)<<ans<<"\n";
	}
	return 0;
}