#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 400010
//AC自动机 P5357
string pat[N],S;
int trie[N][26],fail[N],du[N],cnt=0,que[N],ans[N];
int endNode[N];
void insert(string &s, int idx){
	int now=0;
	for(auto c:s){
		int t=c-'a';
		if(!trie[now][t]) trie[now][t]=++cnt;
		now=trie[now][t];
	}
	endNode[idx]=now;
}
void build(){
	queue<int>q;
	for(int i=0;i<26;i++){
		if(trie[0][i]) q.push(trie[0][i]);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			if(trie[u][i]){
				fail[trie[u][i]]=trie[fail[u]][i];
				du[trie[fail[u]][i]]++;
				q.push(trie[u][i]);
			}
			else{
				trie[u][i]=trie[fail[u]][i];
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pat[i];
		insert(pat[i],i);
	}
	cin>>S;
	build();
	int now=0;
	for(auto c:S){
		int t=c-'a';
		now=trie[now][t];
		que[now]++;
	}
	queue<int> q;
	for(int i=0;i<=cnt;i++){
		if(du[i]==0) q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(fail[u]){
			que[fail[u]]+=que[u];
			du[fail[u]]--;
			if(du[fail[u]]==0) q.push(fail[u]);
		}
	}
	for(int i=1;i<=n;i++){
		ans[endNode[i]]=que[endNode[i]];
		cout<<ans[endNode[i]]<<"\n";
	}
	return 0;
}