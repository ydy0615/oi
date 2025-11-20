#include<bits/stdc++.h>
using namespace std;
int ans[14],check[3][28]={0},sum=0,n;
void dfs(int num){
	if(num>n){
		sum++;
		if(sum>3) return;
		else{
			for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
			cout<<'\n';
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(!check[0][i] && !check[1][num+i] && !check[2][num-i+n]){
			ans[num]=i;
			check[0][i]=1; check[1][num+i]=1; check[2][num-i+n]=1;
			dfs(num+1);
			check[0][i]=0; check[1][num+i]=0; check[2][num-i+n]=0;
		}
	}
}
int main(){
	cin>>n;
	dfs(1);
	cout<<sum<<"\n";
	return 0;
}