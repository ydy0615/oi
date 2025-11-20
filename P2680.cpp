#include<bits/stdc++.h>
using namespace std;
#define N 600010
vector<pair<int,int> > t[N];
int fa[N][20],dis[N][20],dep[N];
int info[N][5],c[N],cnt;
void dfs(int u,int f,int d,int p){
	fa[u][0]=f;
	dis[u][0]=p;
	dep[u]=d;
	for(auto i:t[u]){
		int v=i.first,w=i.second;
		if(v==f) continue;
		dfs(v,u,d+1,w);
	}
}
void dfs2(int u,int f){
	for(auto i:t[u]){
		int v=i.first;
		if(v==f) continue;
		dfs2(v,u);
		c[u]+=c[v];
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,ma=0,len;
	cin>>n>>m;
	for(int i=1,u,v,w;i<n;i++){
		cin>>u>>v>>w;
		t[u].push_back({v,w});
		t[v].push_back({u,w});
	}
	dfs(1,0,1,0);
	for(int i=1;i<=18;i++){
		for(int j=1;j<=n;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
			dis[j][i]=dis[fa[j][i-1]][i-1]+dis[j][i-1];
		}
	}
	for(int i=1,u,v,x,y;i<=m;i++){
		cin>>u>>v;
		len=0;
		x=u,y=v;
		if(dep[x]<dep[y]) swap(x,y);
		for(int j=18;j>=0;j--){
			if(dep[fa[x][j]]>=dep[y]){
				len+=dis[x][j];
				x=fa[x][j];
			}
		}
		if(x!=y){
			for(int j=18;j>=0;j--){
				if(fa[x][j]!=fa[y][j]){
					len+=dis[y][j]+dis[x][j];
					x=fa[x][j];
					y=fa[y][j];
				}
			}
			len+=dis[x][0]+dis[y][0];
			x=fa[x][0];
			y=fa[y][0];
		}
		ma=max(len,ma);
		info[i][0]=u;
		info[i][1]=v;
		info[i][2]=x;
		info[i][3]=len;
	}
	int l=0,r=ma,mid,num;
	while(l<r){
		mid=(l+r)>>1;
		cnt=num=0;
		for(int i=1;i<=m;i++){
			if(info[i][3]>mid){
				c[info[i][0]]++;
				c[info[i][1]]++;
				c[info[i][2]]-=2;
				cnt++;
			}
		}
		dfs2(1,0);
		for(int i=1;i<=n;i++){
			if(c[i]==cnt) num=max(num,dis[i][0]);
			c[i]=0;
		}
		if(ma-num<=mid) r=mid;
		else l=mid+1;
	}
	cout<<l<<"\n";
	return 0;
}