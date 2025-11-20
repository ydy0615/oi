#include<bits/stdc++.h>
using namespace std;
int p[22],d[22][22];
int ans,n,m,c,pre,xl,yl,xr,yr,sum;
int b[22][22];
inline int s(int i,int j){
	int a=0;
	if(d[i][j]!=d[i][j+1] && d[i][j+1]<=c) a++;
	if(d[i][j]!=d[i][j-1] && d[i][j-1]<=c) a++;
	if(d[i][j]!=d[i+1][j] && d[i+1][j]<=c) a++;
	if(d[i][j]!=d[i-1][j] && d[i-1][j]<=c) a++;
	return a;
}
void sa(){
	for(double temp=1;temp>=1e-5;temp*=0.99997){
		xl=rand()%n+1,yl=rand()%m+1,xr=rand()%n+1,yr=rand()%m+1;
		sum=pre-s(xl,yl)-s(xr,yr);
		swap(d[xl][yl],d[xr][yr]);
		sum+=s(xl,yl)+s(xr,yr);
		if(sum<pre || exp(-(sum-pre)/temp)*RAND_MAX>rand()){
			pre=sum;
			if(sum<ans){
				ans=sum;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=m;j++){
						b[i][j]=d[i][j];
					}
				}
			}
		}
		else{
			swap(d[xl][yl],d[xr][yr]);
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(time(NULL));
	memset(d,0x3f,sizeof(d));
	int t=1;
	cin>>n>>m>>c;
	for(int i=1;i<=c;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			while(!p[t]) t++;
			b[i][j]=d[i][j]=t;
			p[t]--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(d[i][j]!=d[i][j+1] && d[i][j+1]<=c) ans++;
			if(d[i][j]!=d[i][j-1] && d[i][j-1]<=c) ans++;
			if(d[i][j]!=d[i+1][j] && d[i+1][j]<=c) ans++;
			if(d[i][j]!=d[i-1][j] && d[i-1][j]<=c) ans++;
		}
	}
	ans/=2;
	pre=ans;
	if(n>15) sa(),sa(),sa();
	else if(n<=15) sa();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}