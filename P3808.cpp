#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 4000010
string pat[N],S;
int trie[N][26],fail[N],cnt=0,ans[N];
int endNode[N];
void insert(string &s, int idx){
	int now=0;
	for(auto c:s){
		int t=c-'a';
		if(!trie[now][t]) trie[now][t]=++cnt;
		now=trie[now][t];
	}
	endNode[idx] = now;
}
void build(){
	queue<int>q;
	for(int i=0;i<26;i++){
		if(trie[0][i]) q.push(trie[0][i]);
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<26;i++){
			if(trie[u][i]){
				fail[trie[u][i]]=trie[fail[u]][i];
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
		ans[now]++;
	}
	queue<int> q;
	for(int i=0;i<=cnt;i++){
		if(fail[i]) q.push(i);
	}
	for(int i=cnt;i>=0;i--){
		int u=i;
		if(fail[u]) {
			ans[fail[u]]+=ans[u];
		}
	}
	int anss=0;
	for(int i=1;i<=n;i++){
		if(ans[endNode[i]]>0) anss++;
	}
	cout<<anss<<"\n";
	return 0;
}