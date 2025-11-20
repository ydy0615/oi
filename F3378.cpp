#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
pair<int,int> a[N];
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.second<y.second;
}
bool cmp2(pair<int,int> x,pair<int,int> y){
	return x.first>y.first;
}
int ma[N],nxt[N],pre[N],s[N];
int fe(int l,int r,int kl,int kr){
	int mid=(l+r)>>1;
	
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(ma,-inf,sizeof(ma));
		int n,k,ans=-inf,cnt=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i].first>>a[i].second;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			s[i]=a[i].first;
			nxt[i]=i+1;
			pre[i]=i-1;
		}
		sort(a+1,a+n+1,cmp);
		cout<<ans<<"\n";
	}
	return 0;
}