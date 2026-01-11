#include<bits/stdc++.h>
using namespace std;
#define N 100010
int a[N],tree[N];
int lb(int x){
	return x&(-x);
}
int ask(int x){
	int res=0;
	while(x){
		res+=tree[x];
		x-=lb(x);
	}
	return res;
}
void add(int x,int y){
	while(x<=100000){
		tree[x]+=y;
		x+=lb(x);
	}
}
int L[N],R[N];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		add(a[i],1);
		L[i]=ask(a[i]-1);
	}
	memset(tree,0,sizeof(tree));
	for(int i=n;i>=1;i--){
		add(a[i],1);
		R[i]=(n-i+1)-ask(a[i]);
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=1ll*L[i]*R[i];
	}
	cout<<ans<<"\n";
	return 0;
}