#include<bits/stdc++.h>
using namespace std;
#define N 1000010
long long pre[N],nxt[N],a[N],n,t[N],tmp,x,ans=0;
bool cmp(int x,int y){
	return nxt[x]-pre[x]<nxt[y]-pre[y];
}
int main(){
	cin>>n;
	for(int i=1,x;i<=n*2;i++){
		cin>>x;
		if(pre[x]) nxt[x]=i;
		else pre[x]=i;
		x=i;
		for(;x<=n*2;x+=x&(-x)) t[x]--;
		a[i]=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		ans++;
		tmp=0;
		x=nxt[a[i]]-1;
		for(;x;x-=x&(-x)) tmp+=t[x];
		ans+=tmp;
		tmp=0;
		x=pre[a[i]];
		for(;x;x-=x&(-x)) tmp+=t[x];
		ans-=tmp;
		x=nxt[a[i]];
		for(;x<=n*2;x+=x&(-x)) t[x]--;
		x=pre[a[i]];
		for(;x<=n*2;x+=x&(-x)) t[x]--;
	}
	cout<<ans;
}