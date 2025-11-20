#include<bits/stdc++.h>
using namespace std;
#define N 2010
#define int long long
struct node{
	int x,y,num,id;
}a[N*N];
bool cmp(node x,node y){
	return x.num<y.num;
}
int fa[N*N],v[N*N],s[N*N];
int b[N*N],top;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void add(int x,int y){
	if(b[x]<=b[y]){
		x=find(x),y=find(y);
		if(x!=y){
			fa[x]=y;
			s[y]|=s[x];
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(b,0x3f,sizeof(b));
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=2000000;i++) fa[i]=i;
	for(int i=1,x;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x;
			a[++top]={i,j,abs(x),i*1000+j};
			b[i*1000+j]=abs(x);
			if(x>0) v[i*1000+j]=1;
		}
	}
	sort(a+1,a+top+1,cmp);
	for(int i=1;i<=top;i++){
		add((a[i].x+1)*1000+(a[i].y),a[i].id);
		add((a[i].x-1)*1000+(a[i].y),a[i].id);
		add((a[i].x)*1000+(a[i].y+1),a[i].id);
		add((a[i].x)*1000+(a[i].y-1),a[i].id);
		if(a[i].num!=a[i+1].num){
			for(int j=i;;j--){
				if(a[j].num!=a[i].num) break;
				if(v[a[j].id]){
					if(!s[find(a[j].id)]){
						s[find(a[j].id)]=1;
						ans++;
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}