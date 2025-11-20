#include<bits/stdc++.h>
using namespace std;
#define N 80
int a[N],v[N],b[N][N];
vector<pair<int,int> > mp[110];
int vis[N],ck[N],rt,cnt=0;
int f[N],g[N],hp[N][N][2],full[N];
vector<int> hc,S;
vector<int> h[N];
int dis(int x,int y,int z){
	int ans=max(x,y)-min(x,y);
	ans=min(ans,x+z-y);
	ans=min(ans,y+z-x);
	return ans;
}
int dfs1(int u,int f){
	cout<<u<<" "<<f<<endl;
	vis[u]=1;
	int flg=0;
	cout<<u<<" "<<f<<endl;
	for(auto i:mp[u]){
		cout<<u<<" "<<f<<" "<<v<<" "<<cnt<<endl;
		int v=i.first;
		cout<<u<<" "<<f<<" "<<v<<" "<<cnt<<endl;
		if(v==f){f=0;continue;}
		cout<<u<<" "<<f<<" "<<v<<" "<<cnt<<endl;
		if(vis[v]){
			cout<<u<<" # "<<f<<" "<<v<<" "<<cnt<<endl;
			rt=v;
			ck[u]=1;
			h[cnt].push_back(u);
			flg=1;
			if(v==u) flg=0;
			cout<<u<<" # "<<f<<" "<<v<<" "<<cnt<<endl;
			continue;
		}
		int tmp=dfs1(v,u);
		cout<<u<<" $ "<<f<<" "<<v<<" "<<cnt<<" "<<flg<<" "<<tmp<<endl;
		if(tmp){
			ck[u]=1;
			h[cnt].push_back(u);
			cout<<u<<" * "<<f<<" "<<v<<" "<<cnt<<" "<<flg<<" "<<tmp<<endl;
			if(u==rt) return 0;
			else return 1;
			cout<<u<<" * "<<f<<" "<<v<<" "<<cnt<<" "<<flg<<" "<<tmp<<endl;
		}
		cout<<u<<" & "<<f<<" "<<v<<" "<<cnt<<" "<<flg<<" "<<tmp<<endl;
	}
	cout<<u<<" $ "<<f<<" "<<v<<" "<<cnt<<" "<<flg<<endl;
	if(flg) return 1;
	else return 0;
}
void dfs2(int u,int fa){
	if(v[u]) g[u]=0;
	for(auto i:mp[u]){
		int v=i.first,w=i.second;
		if(v!=fa || ck[v]) dfs2(v,u);
		f[u]=max(f[u],f[v]);
		g[u]=min(g[u],g[v]);
	}
	g[u]++;
	f[u]++;
	if(f[u]+g[u]<=rt){
		f[u]=0;
	}
	if(f[u]+b[u][fa]>rt){
		cnt++;
		g[u]=0;
		f[u]=0;
	}
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1,x;i<=n;i++){
		cin>>x;
		mp[i].push_back({a[i]+1,x});
		mp[a[i]+1].push_back({i,x});
		b[i][a[i]+1]=x;
		b[a[i]+1][i]=x;
		cout<<i<<" "<<a[i]+1<<" "<<x<<endl;
	}
	for(int i=1,x;i<=m;i++){
		cin>>x;
		v[x]=1;
		S.push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		cnt=i;
		hc.push_back(i);
		cout<<i<<" ############ "<<endl;
		dfs1(i,0);
		cout<<i<<" : ";
		int k=0,d=0,pre;
		for(int j:h[i]){
			hp[i][j][0]=++k;
			if(k) d+=b[pre][j];
			hp[i][j][1]=d;
			pre=j;
			cout<<j<<" ";
		}
		full[i]=d+b[pre][h[i][0]];
		cout<<endl;
		for(int j:h[i]){
			cout<<hp[i][j][0]<<" "<<hp[i][j][1]<<endl;
		}
	}
	/*int l=0,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		rt=mid;cnt=0;
		memset(g,0x3f,sizeof(g));
		memset(f,0,sizeof(f));
		vector<pair<int,int> > tmp; 
		for(int i=1;i<=n;i++){
			if(ck[i]) dfs2(i,0);
		}
		for(int k:hc){
			for(int i:h[k]){
				int flg=1;
				for(int j:h[k]){
					if(f[j]+g[j]+dis(hp[k][i][1],hp[k][j][1],full[k])<=mid){
						flg=0;
						break;
					}
				}
				if(!flg) continue;
				for(int j:S){
					if(hp[k][j][0]){
						if(f[j]+dis(hp[k][i][1],hp[k][j][1],full[k])<=mid){
							flg=0;
							break;
						}
					}
				}
				if(!flg) continue;
				tmp.push_back({i,mid-f[i]});
			}
			cout<<k<<" : \n";
			for(auto j:tmp){
				cout<<j.first<<" "<<j.second<<endl;
			}
		}
	}*/
	return 0;
}