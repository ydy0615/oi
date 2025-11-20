#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define mod 1000000000
#define int long long
int fa[N],vis[N],len,ops[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void p(int x,int y){fa[x]=y;}
int add(int x,int y,int c){
	x=find(x);y=find(y);
	if(c){
		if(x==y) return 0;
		if(x==ops[y]) return 1;
		p(x,ops[y]);
		p(ops[x],y);
	}
	else{
		if(x==ops[y]) return 0;
		if(x==y) return 1;
		p(x,y);
		p(ops[x],ops[y]);
	}
	return 1;
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k,flg=0;
	cin>>n>>m>>k;
	len=n+m;
	for(int i=1;i<=len;i++){
		ops[i+len]=fa[i]=i;
		ops[i]=fa[i+len]=i+len;
	}
	for(int i=1,x,y,c;i<=k;i++){
		cin>>x>>y>>c;
		if(x%2==1 && y%2==1) c^=1;
		y+=n;
		if(!add(x,y,c)){
			flg=1;
			break;
		}
	}
	if(flg){
		cout<<"0\n";
		return 0;
	}
	int tmp=find(1),ans=0;
	vis[tmp]=vis[ops[tmp]]=1;
	for(int i=2,x;i<=len;i++){
		x=find(i);
		if(!vis[x]) ans++;
		vis[x]=vis[ops[x]]=1;
	}
	cout<<qpow(2,ans)<<'\n';
	return 0;
}