#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 7528443412579576937
long double qmi(long double a,int d){
	long double ans=1;
	while(d){
		if(d&1){
			ans=ans*a;
			while(ans>mod) ans-=mod;
		}
		a=a*a;
		while(a>mod) a-=mod;
		d>>=1;
	}
	return ans;
}
signed main(){
	long double b,d,s;
	int n;
	cin>>b>>d>>n;
	s=(b+sqrt(d))/2.0;
	cout<<(long long)qmi(s,n)<<endl;
	return 0;
}