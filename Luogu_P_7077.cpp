#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define mod 998244353
int a[N],du[N];
struct node{
	int op,x,y,mul;
	vector<int> to;
}g[N];
int n,m,q;
void tp(){
	queue<int> q;
	for(int i=1;i<=m;i++){
		if(du[i]==0) q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u].to){
			
			du[v]--;
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1,op,x,y;i<=m;i++){
		cin>>op;
		if(op==1){
			cin>>x>>y;
			g[i].op=1;
			g[i].x=x;
			g[i].y=y;
		}
		if(op==2){
			cin>>x;
			g[i].op=2;
			g[i].x=x;
		}
		if(op==3){
			cin>>x;
			for(int j=1;j<=x;j++){
				cin>>y;
				du[i]++;
				g[y].to.push_back(i);
			}
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){

	}
	return 0;
}