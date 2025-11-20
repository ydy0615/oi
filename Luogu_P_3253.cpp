#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define int long long
int tree[N],n,m,top;
pair<int,int> num[N];
int lb(int x){return x&(-x);}
void add(int x,int y){
	for(;x<=n+m;x+=lb(x)) tree[x]+=y;
}
int ask(int x){
	int ans=0;
	for(;x;x-=lb(x)) ans+=tree[x];
	return ans;
}
signed main(){
	cin>>n>>m;
	for(int i=n,x;i>=1;i--){
		cin>>x;
		num[i]={x,i};
		add(i,1);
	}
	for(int i=1,x;i<=m;i++){
		cin>>x;
		num[i+n]={x,i+n};
		add(i+n,1);
	}
	sort(num+1,num+1+n+m);
	top=n;
	int ans=0;
	for(int i=n+m;i>=1;i--){
		if(!num[i].second) continue;
		if(num[i].second<=top){
			ans+=ask(top)-ask(num[i].second);
			add(num[i].second,-1);
			top=num[i].second;
		}
		else{
			ans+=ask(num[i].second-1)-ask(top);
			add(num[i].second,-1);
			top=num[i].second;
		}
	}
	cout<<ans<<"\n";
	return 0;
}