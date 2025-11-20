#include<bits/stdc++.h>
using namespace std;
#define N 100
#define mod 10000
#define int long long
int n;
struct m{
	int a[N][N];
	m operator*(const m &b) const {
		m res;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				res.a[i][j]=0;
				for(int k=1;k<=n;k++){
					res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j])%mod;
				}
			}
		}
		return res;
	}
	void print(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}mp,v,vj[13],ones,tmp,ap;
m qmi(m a,int b){
	m ans=ones;
	while(b){
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
signed main(){
	int m,s,t,k,f;
	cin>>n>>m>>s>>t>>k;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		u++;v++;
		mp.a[u][v]=1;
		mp.a[v][u]=1;
	}
	for(int i=1;i<=n;i++){
		ones.a[i][i]=1;
	}
	for(int i=0;i<=12;i++){
		vj[i]=mp;
	}
	cin>>f;
	for(int i=1,op,x[10];i<=f;i++){
		cin>>op;
		for(int j=1;j<=op;j++){
			cin>>x[j];
			x[j]++;
		}
		for(int l=1;l<=n;l++){
			for(int j=0;j<=12;j++){
				vj[j].a[l][x[j%op+1]]=0;
			}
		}
	}
	ap=ones;
	for(int i=1;i<=12;i++) ap=ap*vj[i];
	tmp=qmi(ap,k/12);
	for(int i=1;i<=k%12;i++){
		tmp=tmp*vj[i];
	}
	cout<<tmp.a[s+1][t+1]<<endl;
	return 0;
}