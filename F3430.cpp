#include<bits/stdc++.h>
using namespace std;
#define N 200010
priority_queue<int> q;
int b[N];
vector<int> e[N];
int main(){
	int n,m,ans;
	cin>>n>>m;
	ans=n;
	for(int i=1,x,y;i<=n;i++){
		cin>>x>>y;
		e[y+1].push_back(x);
	}
	for(int i=1;i<=2e5+1;i++) b[i]=n;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		b[x]=y;
	}
	for(int i=2;i<=2e5+1;i++) b[i]=min(b[i],b[i-1]);
	for(int i=2e5+1;i>=1;i--){
		for(int j:e[i]) q.push(-j);
		while(q.size()>b[i]){
			ans--;
			e[-q.top()].push_back(0);
			q.pop();
		}
	}
	cout<<ans<<"\n";
	return 0;
}