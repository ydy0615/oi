#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
int a[N],f[N][20];
int st[N],top,nxt[N][20];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i][0]=a[i];
	}
	for(int i=1;i<=n;i++){
		while(top && a[st[top]]<a[i]){
			nxt[st[top]][0]=i;
			top--;
		}
		st[++top]=i;
	}
	while(top) nxt[st[top--]][0]=n+2;
	nxt[n+1][0]=nxt[n+2][0]=n+2;
	for(int j=1;j<=n;j++){
		f[j][0]=a[j]*(nxt[j][0]-j);
	}
	for(int i=1;i<=19;i++){
		for(int j=1;j<=n+2;j++){
			nxt[j][i]=n+2;
		}
		for(int j=1;j<=n;j++){
			nxt[j][i]=nxt[nxt[j][i-1]][i-1];
			f[j][i]=f[j][i-1]+f[nxt[j][i-1]][i-1];
		}
	}
	int lastans=0,ans;
	for(int i=1,u,v,x,y;i<=q;i++){
		cin>>u>>v;
		x=1+(u^lastans)%n;
		y=1+(v^(lastans+1))%(n-x+1);
		y+=x;
		ans=0;
		for(int i=19;i>=0;i--){
			if(nxt[x][i]<y){
				ans+=f[x][i];
				x=nxt[x][i];
			}
		}
		//cout<<x<<" "<<y<<endl;
		ans+=a[x]*(y-x);
		lastans=ans;
		cout<<ans<<"\n";
	}
	return 0;
}