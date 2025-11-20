#include<bits/stdc++.h>
using namespace std;
#define N 300010
vector<int> t[N];
int p1[N][2],p2[N][2],fa[N];
void dfs(int u,int f){
	fa[u]=f;
	int ma1=0,ma2=0,sum=0;
	for(int v:t[u]){
		sum++;
		if(v==f) continue;
		dfs(v,u);
		if(p1[v][0]>=p1[ma1][0]){
			ma2=ma1;
			ma1=v;
		}
		else if(p1[v][0]>=p1[ma2][0]){
			ma2=v;
		}
	}
	p1[u][0]=p1[ma1][0]+sum;
	p1[u][1]=ma1;
	p2[u][0]=p2[ma2][0]+sum;
	p2[u][1]=ma2;
	if(ma1) p1[u][0]--;
	if(ma2) p2[u][0]--;
}
int main(){
	int n,m,ans=0;
	cin>>n>>m;
	if(n==1){
		cout<<"1\n";
		return 0;
	}
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(p1[i][0]==0) dfs(i,0);
	}
	for(int i=1;i<=n;i++){
		int sum1=p1[i][0],sum2;
		if(i==p1[fa[i]][1]){
			sum2=p2[fa[i]][0];
		}
		else{
			sum2=p1[fa[i]][0];
		}
		ans=max(ans,sum1+sum2);
		//cout<<i<<" "<<sum1+sum2<<endl;
	}
	cout<<ans<<endl;
	return 0;
}