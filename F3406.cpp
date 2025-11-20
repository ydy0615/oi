#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define inf 0x3f3f3f3f
int mi[N],ma[N],len;
int mn[N],mx[N],cnt[N],vis[N];
long long ans=0;
void solve(int l,int r){
	if(l==r){
		if(mi[l]>=l && ma[l]<=l) ans++;
		return ;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	for(int i=l;i<=mid;i++){
		cnt[i]=0;
	}
	mn[mid]=mi[mid];
	mx[mid]=ma[mid];
	if(mn[mid]>=mid) vis[mid]=1;
	else vis[mid]=0;
	for(int i=mid-1;i>=l;i--){
		mn[i]=min(mn[i+1],mi[i]);
		mx[i]=max(mx[i+1],ma[i]);
		if(mn[i]>=i) vis[i]=1;
		else vis[i]=0;
	}
	mn[mid+1]=mi[mid+1];
	mx[mid+1]=ma[mid+1];
	if(mx[mid+1]<=mid+1) vis[mid+1]=1;
	else vis[mid+1]=0;
	for(int i=mid+2;i<=r;i++){
		mn[i]=min(mn[i-1],mi[i]);
		mx[i]=max(mx[i-1],ma[i]);
		if(mx[i]<=i) vis[i]=1;
		else vis[i]=0;
	}
	for(int i=mid+1;i<=r;i++){
		if(vis[i]){
			cnt[min(mid,mn[i])]++;
		}
	}
	int sum=0,ct=mid+1;
	for(int i=mid;i>=l;i--){
		sum+=cnt[i];
		while(ct<=r && mx[i]>ct){
			if(vis[ct]){
				if(mn[ct]>=i) sum--;
				else cnt[mn[ct]]--;
			}
			ct++;
		}
		if(vis[i]) ans+=sum;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int C,n,m,sum,l,r,mid,B,top;
	cin>>C>>n>>m;
	for(int i=1;i<=n;i++){
		mi[i]=inf;
		ma[i]=-inf;
	}
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		mi[u]=min(mi[u],v);
		ma[u]=max(ma[u],v);
	}
	solve(1,n);
	cout<<ans<<"\n";
	return 0;
}