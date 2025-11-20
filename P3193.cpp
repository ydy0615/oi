#include<bits/stdc++.h>
using namespace std;
#define N 30
#define int long long
int a[N],nxt[N][N];
int n,m,kp;
struct ma{
	int a[N][N];
	ma operator*(const ma &b) const {
		ma res;
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				res.a[i][j]=0;
				for(int k=0;k<m;k++){
					res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j])%kp;
				}
			}
		}
		return res;
	}
	void print(){
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}f,ones,ans;
ma qmi(ma a,int b){
	ma ans=ones;
	while(b){
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
signed main(){
	int anss=0;
	char ch;
	cin>>n>>m>>kp;
	for(int i=1;i<=m;i++){
		cin>>ch;
		a[i]=ch-'0';
	}
	int j=0;
	for(int i=0;i<=m;i++){
		int ttmp=a[i+1];
		for(int num=0;num<=9;num++){
			int tmp=0;
			a[i+1]=num;
			for(int j=1;j<=i;j++){
				int flg=1;
				for(int k=1;k<=j;k++){
					if(a[k]!=a[i+1-j+k]){
						flg=0;
						break;
					}
				}
				if(flg) tmp=j;
			}
			//cout<<i<<" "<<num<<" "<<ttmp<<" "<<tmp<<endl;
			if(ttmp==num && i!=m) nxt[i][num]=i+1;
			else nxt[i][num]=tmp;
		}
		a[i+1]=ttmp;
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=9;j++){
			//cout<<nxt[i][j]<<" ";
		}
		//cout<<endl;
	}
	for(int i=0;i<m;i++){
		ones.a[i][i]=1;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			for(int l=0;l<=9;l++){
				if(nxt[i][l]==j) f.a[i][j]++;
			}
		}
	}
	ans.a[0][0]=1;
	ans=ans*qmi(f,n);
	for(int i=0;i<m;i++){
		anss=(anss+ans.a[0][i])%kp;
	}
	cout<<anss<<endl;
	return 0;
}