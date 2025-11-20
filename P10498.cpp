#include<bits/stdc++.h>
using namespace std;
#define N 70
#define int unsigned long long
int a[N][N];
string s[N];
char b[N][N][N];
int len,n,m;
struct ma{
	int a[N][N];
	ma operator*(const ma &b) const {
		ma res;
		for(int i=1;i<=len;i++){
			for(int j=1;j<=len;j++){
				res.a[i][j]=0;
				for(int k=1;k<=len;k++){
					res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j]);
				}
			}
		}
		return res;
	}
	void print(){
		for(int i=1;i<=len;i++){
			for(int j=1;j<=len;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}ones,f[N],st,ans;
ma qmi(ma a,int b){
	ma ans=ones;
	while(b){
		if(b&1){
			ans=ans*a;
		}
		a=a*a;
		b>>=1;
	}
	return ans;
}
bool pos(int x,int y){
	if(x<1 || x>n) return 0;
	if(y<1 || y>m) return 0;
	return 1;
}
signed main(){
	int t,act,maxx=0;
	char ch;
	cin>>n>>m>>t>>act;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ch;
			a[i][j]=ch-'0';
		}
	}
	for(int i=1;i<=act;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=60;k++){
				b[i][j][k]=s[a[i][j]+1][(k-1)%(s[a[i][j]+1].size())];
			}
		}
	}
	len=n*m+1;
	for(int i=1;i<=len;i++){
		ones.a[i][i]=1;
	}
	for(int k=1;k<=60;k++){
		f[k]=ones;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(isdigit(b[i][j][k])){
					f[k].a[len][(i-1)*m+j]=b[i][j][k]-'0';
				}
				else if(b[i][j][k]=='D'){
					f[k].a[(i-1)*m+j][(i-1)*m+j]=0;
				}
				else if(b[i][j][k]=='N'){
					f[k].a[(i-1)*m+j][(i-1)*m+j]=0;
					if(pos(i-1,j)) f[k].a[(i-1)*m+j][(i-2)*m+j]=1;
				}
				else if(b[i][j][k]=='S'){
					f[k].a[(i-1)*m+j][(i-1)*m+j]=0;
					if(pos(i+1,j)) f[k].a[(i-1)*m+j][i*m+j]=1;
				}
				else if(b[i][j][k]=='W'){
					f[k].a[(i-1)*m+j][(i-1)*m+j]=0;
					if(pos(i,j-1)) f[k].a[(i-1)*m+j][(i-1)*m+j-1]=1;
				}
				else if(b[i][j][k]=='E'){
					f[k].a[(i-1)*m+j][(i-1)*m+j]=0;
					if(pos(i,j+1)) f[k].a[(i-1)*m+j][(i-1)*m+j+1]=1;
				}
			}
		}
	}
	st=ans=ones;
	for(int i=1;i<=60;i++){
		st=st*f[i];
	}
	ans=qmi(st,t/60);
	for(int i=1;i<=t%60;i++){
		ans=ans*f[i];
	}
	for(int i=1;i<len;i++){
		maxx=max(maxx,ans.a[len][i]);
	}
	cout<<maxx<<"\n";
	return 0;
}