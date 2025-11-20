#include<bits/stdc++.h>
using namespace std;
#define N 2060
int n,m,a,b,c,d,del,ans;
int t1[N][N],t2[N][N],t3[N][N],t4[N][N];
void add(int x,int y,int z){
	for(int X=x;X<=n;X+=X&-X){
		for(int Y=y;Y<=m;Y+=Y&-Y){
			t1[X][Y]+=z;
			t2[X][Y]+=z*x;
			t3[X][Y]+=z*y;
			t4[X][Y]+=z*x*y;
		}
	}
}
void range_add(int xa,int ya,int xb,int yb,int z){
	add(xa,ya,z);
	add(xa,yb+1,-z);
	add(xb+1,ya,-z);
	add(xb+1,yb+1,z);
}
int ask(int x,int y){
	int res=0;
	for(int i=x;i;i-=i&-i)
		for(int j=y;j;j-=j&-j)
			res+=(x+1)*(y+1)*t1[i][j]-(y+1)*t2[i][j]-(x+1)*t3[i][j]+t4[i][j];
	return res;
}
int range_ask(int xa,int ya,int xb,int yb){
	return ask(xb,yb)-ask(xb,ya-1)-ask(xa-1,yb)+ask(xa-1,ya-1);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	char ch;
	cin>>ch>>n>>m;
	while(cin>>ch){
		cin>>a>>b>>c>>d;
		if(ch=='L'){
			cin>>del;
			range_add(a,b,c,d,del);
		}
		if(ch=='k'){
			ans=0;
			cout<<range_ask(a,b,c,d)<<"\n";
		}
	}
	return 0;
}