#include<bits/stdc++.h>
using namespace std;
#define N 2000010
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
pair<int,int> a[N];
int c[N];
signed main(){
	int n,m,ans=inf;
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		a[i*2-1]={x,i*2-1};
	}
	for(int i=1,x;i<=n;i++){
		cin>>x;
		a[i*2]={x,i*2};
	}
	sort(a+1,a+n*2+1);
	int l=1,r=n*2;
	while(!c[(a[l].second+1)/2] && l<=n*2){
		if(a[l].second%2){
			if(!m) break;
			m--;
		}
		c[(a[l].second+1)/2]=1;
		l++;
	}
	while(!c[(a[r].second+1)/2] && r>=0){
		if(a[r].second%2){
			if(!m) break;
			m--;
		}
		c[(a[r].second+1)/2]=1;
		r--;
	}
	ans=min(ans,a[r].first-a[l].first);
	while(l>=0){
		l--;
		if(a[l].second%2) m++;
		c[(a[l].second+1)/2]=0;
		while(!c[(a[r].second+1)/2] && r>=0){
			if(a[r].second%2){
				if(!m) break;
				m--;
			}
			c[(a[r].second+1)/2]=1;
			r--;
		}
		ans=min(ans,a[r].first-a[l].first);
	}
	cout<<ans<<"\n";
	return 0;
}