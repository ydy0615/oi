#include<bits/stdc++.h>
using namespace std;
#define N 3010
int a[N],c[N],l[N],tot;
int b[N],vis[N],d[N];
int main(){
	int n,m,ct=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=max(ct+1,a[i]-m);j<=a[i];j++){
			c[j]=1;
		}
		ct=a[i];
	}
	if(c[1]==1){
		cout<<"-1\n";
		return 0;
	}
	int gd=0,flg=0;
	for(int i=1;i<=ct;i++){
		if(c[i] && !flg){
			gd=i;
			flg=1;
		}
		else if(c[i]){
			gd=__gcd(gd,i);
		}
		if(c[i]){
			l[++tot]=i;
		}
	}
	if(gd!=1){
		cout<<"-1\n";
		return 0;
	}
	memset(d,0x3f,sizeof(d));
	d[0]=0;
	while(1){
		int u=-1;
		for(int i=0;i<l[1];i++){
			if(!vis[i] && (u==-1 || d[i]<d[u])) u=i;
		}
		if(u==-1) break;
		vis[u]=1;
		for(int i=2;i<=tot;i++){
			int v=(u+l[i])%l[1];
			if(!vis[v]){
				d[v]=min(d[v],d[u]+l[i]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<l[1];i++){
		ans=max(ans,d[i]-l[1]);
	}
	cout<<ans<<"\n";
	return 0;
}