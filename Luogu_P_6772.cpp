#include<bits/stdc++.h>
using namespace std;
#define N 270
#define int long long
#define inf 0x3f3f3f3f
int c[N],g[N][N],tot,ans[N],f[N];
struct mat{
	int a[N][N];
	mat operator*(const mat &b) const {
		mat res;
		for(int i=1;i<=tot;i++){
			for(int j=1;j<=tot;j++){
				res.a[i][j]=-inf;
				for(int k=1;k<=tot;k++){
					res.a[i][j]=max(res.a[i][j],a[i][k]+b.a[k][j]);
				}
			}
		}
		return res;
	}
	void print(){
		for(int i=1;i<=tot;i++){
			for(int j=1;j<=tot;j++){
				if(a[i][j]<-10) cout<<-1<<" ";
				else cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
}p,tmp,ones,lg[32];
struct node{
	int t,x,y;
}a[N];
bool cmp(node x,node y){
	return x.t<y.t;
}
void update(int b){
	for(int l=0;l<=31;l++){
		if(b&(1<<l)){
			for(int j=1;j<=tot;j++){
				f[j]=ans[j];
				ans[j]=-inf;
			}
			for(int i=1;i<=tot;i++){
				for(int j=1;j<=tot;j++){
					ans[i]=max(ans[i],f[j]+lg[l].a[i][j]);
				}
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(g,-0x3f,sizeof(g));
	int n,m,T,k,ct=0;
	cin>>n>>m>>T>>k;
	tot=n*5;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		for(int j=1;j<=4;j++){
			g[i+j*n][i+(j-1)*n]=0;
		}
	}
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[v][u+(w-1)*n]=c[v];
	}
	for(int i=1,t,x,y;i<=k;i++){
		cin>>t>>x>>y;
		a[i]={t,x,y};
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=tot;j++){
			if(g[i][j]<0) p.a[i][j]=-inf;
			else p.a[i][j]=g[i][j];
			ones.a[i][j]=-inf;
		}
		ones.a[i][i]=0;
		ans[i]=-inf;
	}
	lg[0]=p;
	for(int i=1;i<=31;i++){
		lg[i]=lg[i-1]*lg[i-1];
	}
	ans[1]=0;
	for(int i=1;i<=k;i++){
		update(a[i].t-ct);
		ans[a[i].x]+=a[i].y;
		ct=a[i].t;
	}
	update(T-ct);
	if(ans[1]<0) cout<<"-1\n";
	else cout<<ans[1]+c[1]<<"\n";
	return 0;
}