#include<bits/stdc++.h>
using namespace std;
#define N 2000010
#define inf 0x3f3f3f3f
int d2[N],nxt[N],pre[N],ans[N],n;
string s;
set<int> sol;
void manacher(){
	int l=0,r=-1,cnt=0,sum=0;
	for(int i=1;i<=2*n;i+=2){
		if(i>r){
			for(int j=i;j<=n*2;j++){
				if(i*2-j<0) break;
				if(s[i*2-j]==s[j]){
					nxt[i*2-j]=min(nxt[i*2-j],j*2-i*2);
					pre[j]=min(pre[j],j*2-i*2);
					d2[i]=j-i;
				}
				else break;
			}
			if(i+d2[i]>=r){
				r=i+d2[i];
				l=i-d2[i];
				cnt=i;
			}
		}
		else{
			d2[i]=min(d2[cnt*2-i],r-i);
			if(cnt*2-i+1-pre[cnt*2-i+1]>l) nxt[i-1]=min(pre[cnt*2-i+1],nxt[i-1]);
			int tmp=i+min({d2[i],i-cnt,i-sum});
			for(int j=i+1;j<=tmp;j+=2){
				nxt[i*2-j]=pre[cnt*2+j-i*2];
				pre[j]=nxt[cnt*2-j];
			}
			for(int j=i+d2[i];j<=n*2;j++){
				if(i*2-j<0) break;
				if(s[i*2-j]==s[j]){
					nxt[i*2-j]=min(nxt[i*2-j],j*2-i*2);
					pre[j]=min(pre[j],j*2-i*2);
					d2[i]=j-i;
				}
				else break;
			}
			if(d2[i]>=i-cnt) sum=i;
			if(i+d2[i]>=r){
				r=i+d2[i];
				l=i-d2[i];
				cnt=i;
			}
		}
	}
}
int dfs(int j){
	if(j>n*2) return 0;
	if(ans[j]!=0) return ans[j];
	ans[j]=dfs(j+nxt[j]+2)+1;
	return ans[j];
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	long long anss;
	string str;
	cin>>T;
	while(T--){
		anss=0;
		s.clear();
		cin>>n>>str;
		for(int i=0;i<=n*2;i++){
			nxt[i]=pre[i]=inf;
			ans[i]=d2[i]=0;
		}
		for(int i=1;i<=n;i++){
			s.push_back(str[i-1]);
			s.push_back('#');
		}
		manacher();
		for(int i=0;i<=2*n;i+=2){
			anss+=dfs(i)-1;
		}
		cout<<anss<<"\n";
	}
	return 0;
}