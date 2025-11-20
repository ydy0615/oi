#include<bits/stdc++.h>
using namespace std;
#define N 5000010
#define int long long
int v[N],c[N],d[N],vis[N];
double p[N];
vector<pair<int,int> > g[N];
queue<int> q;
void spfa(){
	memset(d,-0x3f3f,sizeof d);
	d[0]=0;
	q.push(0);
	while(q.size()){
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(auto v:g[x]){
			if(d[v.first]<d[x]+v.second){
				d[v.first]=d[x]+v.second;
				if(!vis[v.first]){
					if(d[v.first]>d[q.front()]) q.push(v.first);
					else q.push(v.first);
					vis[v.first]=1;
				}
			}
		}
	}
}
signed main(){
	int n,qs,ma=0;
	cin>>n>>qs;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>c[i];
		p[i]=1.000000*c[i]/v[i];
		if(p[i]>p[ma]) ma=i;
	}
	for(int i=1;i<=n;i++){
		if(i==ma) continue;
		for(int j=0;j<v[ma];j++){
			g[j].push_back({(j+v[i])%v[ma],c[i]-(j+v[i])/v[ma]*c[ma]});
		}
	}
	spfa();
	for(int i=1,x;i<=qs;i++){
		cin>>x;
		int ans=x/v[ma]*c[ma]+d[x%v[ma]];
		if(ans<0) ans=-1;
		cout<<ans<<"\n";
	}
	return 0;
}