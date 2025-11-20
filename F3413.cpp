#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
#define mod 998244353
int inv[N],fac[N],mul[N];
int C(int n,int m){
	if(m<0||n<m) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string s;
	cin>>n>>s;
	s=" "+s;
	inv[0]=inv[1]=fac[0]=mul[0]=1;
	for(int i=2;i<200000;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<200000;i++){
		fac[i]=fac[i-1]*i%mod;
		inv[i]=inv[i]*inv[i-1]%mod;
		mul[i]=mul[i-1]*2%mod;
	}
	int ans=mul[n]-1;
	for(int l,r=n;r;r=l){
		l=r;
		while(s[l]==s[r]) l--;
		for(int i=r;i>l;i--){
			int L=i-l+1,R=r-i+2;
			ans=(ans+C(n-L,l-1)*(L-mul[i-l]+mod)%mod)%mod;
			ans=(ans+C(n-R,i-1)*(R-mul[r-i+1]+mod)%mod)%mod;
		}
		if(r-l==n) ans=n;
	}
	cout<<ans<<"\n";
	return 0;
}