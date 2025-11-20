#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define mod 99999997
#define int long long
pair<int,int> a[N],b[N];
int q[N];
int t[N],n;
int lb(int x){
	return x&(-x);
}
void add(int x,int y){
	for(;x<=n;x+=lb(x)) t[x]+=y;
}
int ask(int x){
	int ans=0;
	for(;x>=1;x-=lb(x)) ans+=t[x];
	return ans;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i].first;
		b[i].second=i;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		q[a[i].second]=b[i].second;
		//cout<<a[i].second<<" "<<b[i].second<<endl;
	}
	int ans=0;
	for(int i=n;i>=1;i--){
		add(q[i],1);
		ans+=ask(q[i]-1);
	}
	cout<<ans%mod<<"\n";
	return 0;
}