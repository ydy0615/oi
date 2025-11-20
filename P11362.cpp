#include<bits/stdc++.h>
using namespace std;
#define M 100010
#define mod 1000000007
#define int long long
pair<int,int> a[M];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
signed main(){
	int T;
	cin>>T;
	while(T--){
		int n,m,v,ans=1,cnt=1,flag=0;
		cin>>n>>m>>v;
		for(int i=1,c,d;i<=m;i++){
			cin>>c>>d;
			a[i]={c,d};
		}
		sort(a+1,a+m+1);
		if(a[1].first!=1){
			ans=ans*qpow(v,a[1].first*2-2)%mod;
		}
		for(int i=1;i<m;i++){
			if(a[i].first==a[i+1].first && a[i].second!=a[i+1].second){
				flag=1;
				break;
			}
			if(a[i].first!=a[i+1].first){
				ans=ans*((qpow(v,a[i+1].first*2-a[i].first*2)-(qpow(v,a[i+1].first-a[i].first-1)*(v-1)%mod)+mod)%mod)%mod;
			}
		}
		if(a[m].first!=n){
			ans=(ans*qpow(v,n*2-a[m].first*2))%mod;
		}
		if(flag){
			cout<<"0\n";
		}
		else{
			cout<<ans%mod<<"\n";
		}
	}
	return 0;
}