#include<bits/stdc++.h>
using namespace std;
#define N 1000010
int a[N],b[N],bl,s[N][3],cnt[N],num,ans[N];
struct node{
	int l,r,t,num;
}p[N];
bool cmp(node x,node y){
	return (x.l/bl==y.l/bl) ? ((x.r/bl==y.r/bl)? x.t<y.t:x.r/bl<y.r/bl) : x.l/bl<y.l/bl;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,q=0,top=1;
	char ch;
	cin>>n>>m;
	bl=cbrt(1ll*n*n)+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1,x,y;i<=m;i++){
		cin>>ch>>x>>y;
		if(ch=='R'){
			s[++top][0]=x;
			s[top][1]=y;
			s[top][2]=b[x];
			b[x]=y;
		}
		else if(ch=='Q'){
			++q;
			p[q]={x,y,top,q};
		}
	}
	sort(p+1,p+q+1,cmp);
	int l=0,r=0,t=1;
	for(int i=1;i<=q;i++){
		while(r<p[i].r) if(cnt[a[++r]]++==0) num++;
		while(r>p[i].r) if(cnt[a[r--]]--==1) num--;
		while(l<p[i].l) if(cnt[a[l++]]--==1) num--;
		while(l>p[i].l) if(cnt[a[--l]]++==0) num++;
		while(t>p[i].t){
			if(l<=s[t][0] && s[t][0]<=r){
				if(cnt[a[s[t][0]]]--==1) num--;
				if(!cnt[s[t][2]]++) num++;
			}
			a[s[t][0]]=s[t][2];
			t--;
		}
		while(t<p[i].t){
			t++;
			if(l<=s[t][0] && s[t][0]<=r){
				if(cnt[a[s[t][0]]]--==1) num--;
				if(!cnt[s[t][1]]++) num++;
			}
			a[s[t][0]]=s[t][1];
		}
		ans[p[i].num]=num;
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}