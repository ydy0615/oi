#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
int h[N],w[N],t1,t2,s1,s2;
pair<int,int> c1[N],c2[N];
int f1[N*3],f2[N*3];
int cx[N],cy[N];
signed main(){
	int n,q;
	char ch;
	cin>>n>>q;
	for(int i=1,x;i<=n;i++){
		cin>>ch>>x;
		if(ch=='V'){
			h[++t1]=x;
		}
		else if(ch=='H'){
			w[++t2]=x;
		}
	}
	sort(h+1,h+t1+1);
	sort(w+1,w+t2+1);
	int t=1;
	for(int i=2;i<=t1;i++){
		if((h[i]-h[i-1])%2==1){
			c1[++s1].first=t;
			c1[s1].second=h[i]-h[t];
			t=i;
			cx[s1]=h[t];
		}
	}
	if(t!=t1){
		c1[++s1].first=t;
		c1[s1].second=h[t1]-h[t];
		cx[s1]=h[t1];
	}
	t=1;
	for(int i=2;i<=t2;i++){
		if((w[i]-w[i-1])%2==1){
			c2[++s2].first=t;
			c2[s2].second=w[i]-w[t];
			t=i;
			cy[s2]=w[t];
		}
	}
	if(t!=t2){
		c2[++s2].first=t;
		c2[s2].second=w[t2]-w[t];
		cy[s2]=w[t2];
	}
	for(int i=1;i<=s1;i++){
		f1[i]=f1[i-1]+c1[i].second;
	}
	for(int i=s1+1;i<=n*2;i++){
		f1[i]=inf;
	}
	for(int i=1;i<=s2;i++){
		f2[i]=f2[i-1]+c2[i].second;
	}
	for(int i=s2+1;i<=n*2;i++){
		f2[i]=inf;
	}
	while(q--){
		int x,y,d,tx,ty,sum=0;
		cin>>x>>y>>d;
		tx=lower_bound(h+1,h+t1+1,x)-h;
		ty=lower_bound(w+1,w+t2+1,y)-w;
		if(h[tx]==x){
			if(w[ty]==0 || w[ty]-y>d){
				cout<<x<<" "<<y+d<<"\n";
				continue;
			}
			else{
				d-=w[ty]-y;
				sum+=w[ty]-y;
				y=w[ty];
			}
		}
		if(w[ty]==y){
			if(h[tx]==0 || h[tx]-x>d){
				cout<<x+d<<" "<<y<<"\n";
				continue;
			}
			else{
				d-=h[tx]-x;
				sum+=h[tx]-x;
				x=h[tx];
			}
		}
		int flag=0;
		for(int i=1;i<=200000;i++){
			tx=lower_bound(cx+1,cx+s1+1,x)-cx;
			ty=lower_bound(cy+1,cy+s2+1,y)-cy;
			if(x==cx[tx] && y==cy[ty]) break;
			else if(x==cx[tx]){
				tx=lower_bound(cx+1,cx+s1+1,x+1)-cx;
			}
			else if(y==cy[ty]){
				ty=lower_bound(cy+1,cy+s2+1,y+1)-cy;
			}
			if(sum%2==0){
				if(cy[ty]==0 || cy[ty]-y>d){
					cout<<x<<" "<<y+d<<"\n";
					flag=1;
					break;
				}
				else{
					d-=cy[ty]-y;
					sum+=cy[ty]-y;
					y=cy[ty];
				}
			}
			else{
				if(cx[tx]==0 || cx[tx]-x>d){
					cout<<x+d<<" "<<y<<"\n";
					flag=1;
					break;
				}
				else{
					d-=cx[tx]-x;
					sum+=cx[tx]-x;
					x=cx[tx];
				}
			}
		}
		if(flag){
			continue;
		}
		ty=lower_bound(cy+1,cy+s2+1,y)-cy;
		tx=lower_bound(cx+1,cx+s1+1,x)-cx;
		int l=0,r=min(s1-tx-1,s2-ty-1),mid,chk;
		while(l<r){
			mid=(l+r+1)>>1;
			chk=f1[tx+mid]-f1[tx]+f2[ty+mid]-f2[ty];
			if(chk<=d){
				l=mid;
			}
			else r=mid-1;
		}
		x+=f1[tx+l]-f1[tx];
		y+=f2[ty+l]-f2[ty];
		d-=f1[tx+l]-f1[tx]+f2[ty+l]-f2[ty];
		sum+=f1[tx+l]-f1[tx]+f2[ty+l]-f2[ty];
		flag=0;
		for(int i=1;i<=2;i++){
			if(sum%2==0){
				ty=lower_bound(cy+1,cy+s2+1,y+1)-cy;
				if(cy[ty]==0 || cy[ty]-y>d){
					cout<<x<<" "<<y+d<<"\n";
					flag=1;
					break;
				}
				else{
					d-=cy[ty]-y;
					sum+=cy[ty]-y;
					y=cy[ty];
				}
			}
			else{
				tx=lower_bound(cx+1,cx+s1+1,x+1)-cx;
				if(cx[tx]==0 || cx[tx]-x>d){
					cout<<x+d<<" "<<y<<"\n";
					flag=1;
					break;
				}
				else{
					d-=cx[tx]-x;
					sum+=cx[tx]-x;
					x=cx[tx];
				}
			}
		}
		if(flag) continue;
		if(sum%2==0){
			cout<<x<<" "<<y+d<<"\n";
		}
		else{
			cout<<x+d<<" "<<y<<"\n";
		}
	}
	return 0;
}