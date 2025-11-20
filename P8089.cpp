#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define mod 998244353
#define int long long
int b[N];
string S;
signed main(){
	b[1]=1;
	for(int i=2;i<=1000000;i++){
		b[i]=(b[i-1]*b[i-1]+(b[i-1]<<1)+1)%mod;
	}
	int T,n,ans;
	cin>>T;
	while(T--){
		cin>>n>>S;
		if(S[0]=='1') cout<<b[n]<<"\n";
		else{
			ans=0;
			for(int i=n-1;i>=1;i--){
				ans=(ans+1)*(b[n-i-1+S[i]-'0']+1)%mod;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}