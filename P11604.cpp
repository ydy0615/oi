#include<bits/stdc++.h>
using namespace std;
#define N 100010
int a[N],b[N];
int main(){
	int T,n,m;
	char ch;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n>>m;
		for(int i=1,u,v;i<=m;i++){
			cin>>u>>ch>>v;
			if(ch=='>') b[v]++;
			else a[v]++;
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			if(b[i]==n){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"WYGRANA\n";
			continue;
		}
		flag=0;
		for(int i=1;i<=n;i++){
			if(!a[i]){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"REMIS\n";
		}
		else{
			cout<<"PRZEGRANA\n";
		}
	}
	return 0;
}