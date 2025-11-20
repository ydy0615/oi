#include<bits/stdc++.h>
using namespace std;
int trie[4000010][27],num[4000010];
string str[4010];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,top,ans,T=0;
	while(1){
		top=1;
		ans=0;
		T++;
		cin>>n;
		if(n==0){
			break;
			return 0;
		}
		memset(trie,0,sizeof(trie));
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++){
			cin>>str[i];
			int u=1;
			for(char j:str[i]){
				ans+=num[u];
				num[u]++;
				if(trie[u][j-'a']==0){
					trie[u][j-'a']=++top;
					u=top;
				}
				else{
					u=trie[u][j-'a'];
				}
			}
		}
		cout<<"Case "<<T<<": "<<ans<<"\n";
	}
	return 0;
}