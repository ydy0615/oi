#include<bits/stdc++.h>
using namespace std;
#define N 10
#define int __int128
long long mod;
struct m{
	int a[N][N];
	m operator*(const m &b) const {
		m res;
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++){
				res.a[i][j]=0;
				for(int k=1;k<=2;k++){
					res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j])%mod;
				}
			}
		}
		return res;
	}
}a,ans;
void qmi(int b){
	while(b){
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
}
int s(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}
signed main(){
	long long n;
	int tmp;
	cin>>n>>mod;
	if(n<=1){
		cout<<0<<"\n";
		return 0;
	}
	a.a[1][1]=a.a[1][2]=a.a[2][1]=1;
	a.a[2][2]=0;
	ans.a[1][1]=ans.a[1][2]=1;
	qmi(n+1);
	tmp=ans.a[1][1];
	tmp=tmp+mod*10-n-2;
	tmp%=mod;
	cout<<(long long)s(tmp,n+1)<<"\n";
	return 0;
}