#include<bits/stdc++.h>
using namespace std;
#define N 600010
#define M 10000010
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define ull unsigned long long
int a[N],b[M],p=0;
int pre[M],nxt[M],w[N];
pair<int,int> c[M];
ull st[M],top;
int ans[N];
signed main(){
    memset(st,0x3f,sizeof(st));
    int n,m,x0,d,t,rt,ma=0,mi=inf;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
        mi=min(mi,a[i]);
    }
    sort(a+1,a+n+1);
    cin>>x0>>d;
    cin>>m;
    for(int i=1;i<=m;i++) cin>>c[i].first,c[i].second=i;
    ma=max(ma,x0);
    mi=min(mi,x0);
    t=x0%d;
    if(m==1 && c[1].first==0){
        int ans=0;
        for(int i=1;i<=n;i++){
            int tmp=(a[i]-t+d*20)/d;
            tmp=t+(tmp-20)*d;
            ans+=min((tmp-a[i])*(tmp-a[i]),(tmp+d-a[i])*(tmp+d-a[i]));
        }
        cout<<ans<<"\n";
        return 0;
    }
    for(int i=1;i<=n;i++){
        int tmp=(a[i]-t+d*20)/d;
        tmp=t+(tmp-20)*d;
        w[i]=min((tmp-a[i])*(tmp-a[i]),(tmp+d-a[i])*(tmp+d-a[i]));
    }
    int tmp=(mi-t+d*20)/d;
    tmp=t+(tmp-20)*d;
    for(int i=tmp;i<=ma+d;i+=d){
        b[++p]=i;
    }
    sort(b+1,b+p+1);
    int len=unique(b+1,b+p+1)-b-1;
    for(int i=1;i<=len;i++) if(b[i]==x0) rt=i;
    for(int i=1;i<=len;i++){
        pre[i]=0;
        nxt[i]=0;
        for(int j=1;j<=n;j++){
            if(a[j]>b[i]) break;
            pre[i]+=(a[j]-b[i])*(a[j]-b[i]);
        }
        for(int j=n;j>=1;j--){
            if(a[j]<b[i]) break;
            nxt[i]+=(a[j]-b[i])*(a[j]-b[i]);
        }
        if(pre[i]<0) pre[i]=inf;
        if(nxt[i]<0) nxt[i]=inf;
    }
    for(int i=1;i<=len;i++){
        int l=0,r=0;
        ull num=0;
        while(a[r+1]<=b[i] && r+1<=n){
            r++;
            num+=w[r];
        }
        for(int j=i;j<=len;j++){
            while(a[l+1]<=b[j-i+1] && l+1<=n){
                l++;
                num-=w[l];
            }
            while(a[r+1]<=b[j] && r+1<=n){
                r++;
                num+=w[r];
            }
            int tmp1=min(abs(b[j]-x0),abs(b[j-i+1]-x0))+b[j]-b[j-i+1];
            tmp1/=d;
            st[tmp1]=min(st[tmp1],num+pre[j-i+1]+nxt[j]);
        }
    }
    sort(st+1,st+top+1);
    for(int i=0;i<=10000000;i++) if(st[i]<inf) top=i;
    sort(c+1,c+m+1);
    int r=top;
    for(int i=1;i<=m;i++){
        while(r-1>=0 && st[r-1]<inf && st[r-1]+(r-1)*c[i].first<=st[r]+r*c[i].first) r--;
        for(int j=r-1;j>=max(r-100000,0ll);j--){
            if(st[j]<inf && st[j]+j*c[i].first<=st[r]+r*c[i].first){
                r=j;
            }
        }
        ans[c[i].second]=st[r]+r*c[i].first;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
    return 0;
}