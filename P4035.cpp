#include<bits/stdc++.h>
using namespace std;
#define N 510
#define inf 0x3f3f3f3f
#define eps 1e-6
double ip[N][N],a[N][N];
int vis[N],d[N];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++){
			cin>>ip[i][j];
		}
	}
	double dist=0;
	for(int i=1;i<=n;i++){
		dist=0;
		for(int j=1;j<=n;j++){
			dist=dist+ip[i+1][j]*ip[i+1][j]-ip[i][j]*ip[i][j];
			a[i][j]=-2*(ip[i][j]-ip[i+1][j]);
		}
		a[i][n+1]=dist;
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(a[j][i] && !vis[j]){
				u=j;
				break;
			}
		}
		if(u==0) continue;
		d[i]=u;
		vis[u]=1;
		double tmp=a[u][i];
		for(int j=1;j<=n+1;j++){
			a[u][j]/=tmp;
		}
		for(int j=1;j<=n;j++){
			if(a[j][i]==0 || j==u) continue;
			tmp=a[j][i];
			for(int k=1;k<=n+1;k++){
				a[j][k]-=a[u][k]*tmp;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<fixed<<setprecision(3)<<a[d[i]][n+1]<<" ";
	}
	return 0;
}