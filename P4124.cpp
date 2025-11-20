#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[20][3][20][20][20];
int f1[20][3],f3[20][3];
int f2[20][3][20][20];
int check(int x){
	int sum=10000000000ll,tmp,typ=0,flag=0,temp,ans=0,len=11,f=0,j=10,tf,tj,ma=0;
	string str;
	char ch;
	while(1){
		tmp=(x%(sum*10))/sum;
		for(int i=0;i<=tmp;i++){
			if(i==0 && !flag) continue;
			if(i==tmp && sum>=10) break;
			if(i==tmp){
				if((typ==1 && tmp==8) || (typ==2 && tmp==4)) break;
			}
			if(typ==1 && i==8) continue;
			if(typ==2 && i==4) continue;
			temp=typ;
			if(typ==0 && i==8) temp=2;
			if(typ==0 && i==4) temp=1;
			if(i==j) tf=f+1;
			else tf=1;
			tj=i;
			if(ma>=3 || tf>=3){
				ans+=f3[len-1][0];
				if(temp!=2) ans+=f1[len-1][1];
				if(temp!=1) ans+=f3[len-1][2];
			}
			else{
				ans+=f1[len-1][0];
				if(temp!=2) ans+=f1[len-1][1];
				if(temp!=1) ans+=f1[len-1][2];
				if(tf==1){
					ans+=f2[len-1][0][2][tj];
					if(temp!=2) ans+=f2[len-1][1][2][tj];
					if(temp!=1) ans+=f2[len-1][2][2][tj];
				}
				if(tf==2){
					ans+=f2[len-1][0][2][tj];
					ans+=f2[len-1][0][1][tj];
					if(temp!=2) ans+=f2[len-1][1][2][tj];
					if(temp!=1) ans+=f2[len-1][2][2][tj];
					if(temp!=2) ans+=f2[len-1][1][1][tj];
					if(temp!=1) ans+=f2[len-1][2][1][tj];
				}
			}
		}
		if((typ==1 && tmp==8) || (typ==2 && tmp==4)) break;
		if(tmp==8) typ=2;
		if(tmp==4) typ=1;
		ch=tmp+'0';
		str.push_back(ch);
		if(tmp!=j){
			j=tmp;
			f=1;
		}
		else f++;
		ma=max(ma,f);
		flag=1;
		if(sum<=1) return ans;
		sum/=10;
		len--;
	}
	return ans;
}
signed main(){
	int l,r,x,y;
	cin>>l>>r;
	memset(dp,0,sizeof(dp));
	dp[0][0][0][0][10]=1;
	for(int i=0;i<=11;i++){
		for(int j=0;j<=9;j++){
			for(int x=0;x<=11;x++){
				for(int y=0;y<=11;y++){
					for(int z=0;z<=10;z++){
						if(j==4){
							if(z==j) dp[i+1][1][max(x,y+1)][y+1][j]+=dp[i][0][x][y][z]+dp[i][1][x][y][z];
							else dp[i+1][1][max(x,1ll)][1][j]+=dp[i][0][x][y][z]+dp[i][1][x][y][z];
						}
						else if(j==8){
							if(z==j) dp[i+1][2][max(x,y+1)][y+1][j]+=dp[i][2][x][y][z]+dp[i][0][x][y][z];
							else dp[i+1][2][max(x,1ll)][1][j]+=dp[i][2][x][y][z]+dp[i][0][x][y][z];
						}
						else{
							if(z==j){
								dp[i+1][0][max(x,y+1)][y+1][j]+=dp[i][0][x][y][z];
								dp[i+1][1][max(x,y+1)][y+1][j]+=dp[i][1][x][y][z];
								dp[i+1][2][max(x,y+1)][y+1][j]+=dp[i][2][x][y][z];
							}
							else{
								dp[i+1][0][max(x,1ll)][1][j]+=dp[i][0][x][y][z];
								dp[i+1][1][max(x,1ll)][1][j]+=dp[i][1][x][y][z];
								dp[i+1][2][max(x,1ll)][1][j]+=dp[i][2][x][y][z];
							}
						}
					}
				}
			}
		}
	}
	int n=11;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=10;j++){
			for(int y=0;y<=n;y++){
				for(int k=0;k<=2;k++){
					for(int x=0;x<=2;x++){
						f2[i][k][y][j]+=dp[i][k][x][y][j];
						f3[i][k]+=dp[i][k][x][y][j];
					}
					for(int x=3;x<=n;x++){
						f1[i][k]+=dp[i][k][x][y][j];
						f3[i][k]+=dp[i][k][x][y][j];
					}
				}
			}
		}
	}
	if(l==10000000000ll) cout<<check(r)-check(l)+1<<endl;
	else cout<<check(r)-check(l-1)<<endl;
	return 0;
}