#include<bits/stdc++.h>
using namespace std;
#define N 30
#define int long long
int c[N],p[N],l[N];
int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1;
		y=0;
		return a;
	}
	int t=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return t;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>p[i]>>l[i];
		m=max(m,c[i]);
	}
	while(1){
		int f=1;
		for(int i=1,x,y;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				x=y=0;
				int t=exgcd(p[i]-p[j],m,x,y);
				if((c[j]-c[i])%t) continue;
				int mod=abs(m/t);
				x=(x*(((c[j]-c[i]+mod)%mod)/t)%mod+mod)%mod;
				if(x<=l[i] && x<=l[j]){
					f=0;
					break;
				}
			}
			if(!f) break;
		}
		if(f){
			cout<<m<<"\n";
			break;
		}
		m++;
	}
	return 0;
}