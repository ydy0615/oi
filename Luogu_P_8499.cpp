#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define inf 0x3f3f3f3f
#define int unsigned long long
vector<int> t1[N],t2[N];
int rt1,rt2,mask=114514;
int hah1[N],hah2[N],sz1[N],sz2[N];
int shift(int x){
	x^=mask;
	x^=x<<5;
	x^=x>>11;
	x^=x<<54;
	x^=mask;
	return x;
}
void hsh1(int u){
	int sum=1;
	sz1[u]=1;
	for(int i:t1[u]){
		hsh1(i);
		sum+=shift(hah1[i]);
		sz1[u]+=sz1[i];
	}
	hah1[u]=sum;
}
void hsh2(int u){
	int sum=1;
	sz2[u]=1;
	for(int i:t2[u]){
		hsh2(i);
		sum+=shift(hah2[i]);
		sz2[u]+=sz2[i];
	}
	hah2[u]=sum;
}
int dfs(int u1,int u2,int lim){
	if(sz1[u1]<sz2[u2]) return inf;
	if(hah1[u1]==hah2[u2]) return 0;
	if(sz2[u2]==1) return sz1[u1]-1;
	vector<pair<int,int> > mp,p;
	for(int i:t2[u2]) mp.push_back(make_pair(hah2[i],i));
	sort(mp.begin(),mp.end());
	for(int i:t1[u1]){
		auto v=lower_bound(mp.begin(),mp.end(),make_pair(hah1[i],(int)0));
		if(v!=mp.end() && (*v).first==hah1[i]) mp.erase(v);
		else p.push_back(make_pair(hah1[i],i));
	}
	if(p.size()>lim || mp.size()>p.size()) return inf;
	int c[8][8];
	for(int i=0;i<mp.size();i++){
		for(int j=0;j<p.size();j++){
			c[i][j]=dfs(p[j].second,mp[i].second,lim);
		}
	}
	int f[8]={0,1,2,3,4,5,6,7},ans=inf,res;
	do{
		res=0;
		for(int i=0;i<p.size();i++){
			if(f[i]>=mp.size()) res+=sz1[p[i].second];
			else res+=c[f[i]][i];
		}
		ans=min(ans,res);
	}while(next_permutation(f,f+p.size()));
	return ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int C,T,n,m,k;
	cin>>C>>T>>k;
	while(T--){
		cin>>n;
		for(int i=1,x;i<=n;i++){
			t1[i].clear();
			t2[i].clear();
		}
		for(int i=1,x;i<=n;i++){
			cin>>x;
			if(x==-1) rt1=i;
			else t1[x].push_back(i);
		}
		cin>>m;
		for(int i=1,x;i<=m;i++){
			cin>>x;
			if(x==-1) rt2=i;
			else t2[x].push_back(i);
		}
		hsh1(rt1);
		hsh2(rt2);
		if(dfs(rt1,rt2,k)<=k) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}