#include<bits/stdc++.h>
using namespace std;
#define N 510
int a[N][N],c1[N][N],c2[N][N],c3[N][N];
int k;
bool check(int x1,int x2,int y1,int y2){
	if(c3[x2][y2]-c3[x1-1][y2]-c3[x2][y1-1]+c3[x1-1][y1-1]==(y2-y1+1)*(x2-x1+1)){
		return 1;
	}
	if(c3[x2][y2]-c3[x1-1][y2]-c3[x2][y1-1]+c3[x1-1][y1-1]){
		return 0;
	}
	if((y2-y1+1)*(x2-x1+1)-(c1[x2][y2]-c1[x1-1][y2]-c1[x2][y1-1]+c1[x1-1][y1-1])<=k){
		return 1;
	}
	if((y2-y1+1)*(x2-x1+1)-(c2[x2][y2]-c2[x1-1][y2]-c2[x2][y1-1]+c2[x1-1][y1-1])<=k){
		return 1;
	}
	return 0;
}
int main(){
	int n,m,ans=0;
	int an[20];
	char ch;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ch;
			if(ch=='B') a[i][j]=1;
			if(ch=='G') a[i][j]=2;
			if(ch=='P') a[i][j]=3;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c1[i][j]=c1[i-1][j]+c1[i][j-1]-c1[i-1][j-1];
			c2[i][j]=c2[i-1][j]+c2[i][j-1]-c2[i-1][j-1];
			c3[i][j]=c3[i-1][j]+c3[i][j-1]-c3[i-1][j-1];
			if(a[i][j]==1) c1[i][j]++;
			if(a[i][j]==2) c2[i][j]++;
			if(a[i][j]==3) c3[i][j]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x=n;
			for(int y=j;y<=m;y++){
				while(x>=i && !check(i,x,j,y)) x--;
				if(x<i) break;
				if((x-i+1)*(y-j+1)>ans){
					ans=(x-i+1)*(y-j+1);
					an[1]=i;
					an[2]=j;
					an[3]=x;
					an[4]=y;
				}
			}
		}
	}
	cout<<ans<<"\n";
	if((an[4]-an[2]+1)*(an[3]-an[1]+1)-(c1[an[3]][an[4]]-c1[an[1]-1][an[4]]-c1[an[3]][an[2]-1]+c1[an[1]-1][an[2]-1])<=k){
		for(int i=an[1];i<=an[3];i++){
			for(int j=an[2];j<=an[4];j++){
				a[i][j]=1;
			}
		}
	}
	else if((an[4]-an[2]+1)*(an[3]-an[1]+1)-(c2[an[3]][an[4]]-c2[an[1]-1][an[4]]-c2[an[3]][an[2]-1]+c2[an[1]-1][an[2]-1])<=k){
		for(int i=an[1];i<=an[3];i++){
			for(int j=an[2];j<=an[4];j++){
				a[i][j]=2;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==1) cout<<"B";
			if(a[i][j]==2) cout<<"G";
			if(a[i][j]==3) cout<<"P";
		}
		cout<<"\n";
	}
	return 0;
}