#include<bits/stdc++.h>
using namespace std;
#define N 4010000
int trie[N][64],cnt[N],num[N];
long long ans=0;
void dfs(int u,int dep){
	int tmp=num[u];	
	//cout<<u<<" "<<tmp<<" "<<dep<<endl;
	for(int i=0;i<=61;i++){
		if(trie[u][i]!=0){
			dfs(trie[u][i],dep+1);
			ans+=1ll*num[trie[u][i]]*(tmp-num[trie[u][i]])*(dep+1);
			//cout<<num[trie[u][i]]<<" "<<(tmp-num[trie[u][i]])<<" "<<(dep+1)<<endl;
			tmp-=num[trie[u][i]];
		}
	}
	ans+=1ll*cnt[u]*(cnt[u]-1)/2;
}
int main(){
	//freopen("p.in","r",stdin);
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,top=0,_=0,f,x;
	//string str;
	while(1){
		_++;
		cin>>n;
		if(n==0) break;
		for(int i=1;i<=top;i++){
			num[i]=cnt[i]=trie[i][0]=trie[i][1]=trie[i][2]=trie[i][3]=trie[i][4]=trie[i][5]=trie[i][6]=trie[i][7]=trie[i][8]=trie[i][9]=trie[i][10]=trie[i][11]=trie[i][12]=trie[i][13]=trie[i][14]=trie[i][15]=trie[i][16]=trie[i][17]=trie[i][18]=trie[i][19]=trie[i][20]=trie[i][21]=trie[i][22]=trie[i][23]=trie[i][24]=trie[i][25]=trie[i][26]=trie[i][27]=trie[i][28]=trie[i][29]=trie[i][30]=trie[i][31]=trie[i][32]=trie[i][33]=trie[i][34]=trie[i][35]=trie[i][36]=trie[i][37]=trie[i][38]=trie[i][39]=trie[i][40]=trie[i][41]=trie[i][42]=trie[i][43]=trie[i][44]=trie[i][45]=trie[i][46]=trie[i][47]=trie[i][48]=trie[i][49]=trie[i][50]=trie[i][51]=trie[i][52]=trie[i][53]=trie[i][54]=trie[i][55]=trie[i][56]=trie[i][57]=trie[i][58]=trie[i][59]=trie[i][60]=trie[i][61]=0;
		}
		top=1;
		ans=0;
		getchar();
		for(int i=1;i<=n;i++){
			f=1;
			for(int j=0;1;j++){
				num[f]++;
				char ch=getchar();
				if(ch=='\n') break;
				cout<<" $ "<<ch<<" "<<f<<" ";
				if(isdigit(ch)) x=ch-'0';
				else if('a'<=ch && ch<='z') x=ch-'a'+10;
				else if('A'<=ch && ch<='Z') x=ch-'A'+36;
				cout<<x<<endl;
				if(trie[f][x]==0) trie[f][x]=++top;
				f=trie[f][x];
			}
			num[f]++;
			cnt[f]++;
		}
		dfs(1,0);
		cout<<"Case "<<_<<": "<<ans<<"\n";
	}
	return 0;
}