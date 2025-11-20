#include<bits/stdc++.h>
using namespace std;
#define N 10000010
#define int long long
int a[N];
int s[N],top=0;
struct node{
	int lc,rc;
}tree[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans1=0,ans2=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s[++top]=1;
	for(int i=2;i<=n;i++){
		while(a[s[top]]>a[i] && top) top--;
		if(!top){
			tree[i].lc=s[top+1];
		}
		else{
			tree[i].lc=tree[s[top]].rc;
			tree[s[top]].rc=i;
		}
		s[++top]=i;
	}
	for(int i=1;i<=n;i++){
		ans1^=i*(tree[i].lc+1);
		ans2^=i*(tree[i].rc+1);
	}
	cout<<ans1<<" "<<ans2<<"\n";
	return 0;
}