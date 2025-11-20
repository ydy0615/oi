#include<bits/stdc++.h>
using namespace std;
#define N 2010
#define mod 1000000007
int a[N][N],c[N][N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	int n,ans=0;
	char ch;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>ch;
			if(ch=='.') a[i][j]=0;
			else a[i][j]=1;
			c[i][j]=c[i-1][j]+c[i][j-1]+(!a[i][j])-c[i-1][j-1];
		}
	}
	cout<<ans<<endl;
	return 0;
}