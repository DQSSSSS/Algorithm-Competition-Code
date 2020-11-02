#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,double>
using namespace std;
const double eps=1e-8;
const double INF=1e18;
int sgn(double x){
    if(-eps<x&&x<eps)return 0;
    if(x<=-eps)return -1;
    return 1;
}
vector<pa>G[1004];
queue<int>q;
int n,m,c[1004];
short unk[1004],inq[1004];
double o[1004],dis[1004];
int a[2004],b[2004],d[2004];
bool check(double Val){
    while(!q.empty())q.pop();
    for(int i=0;i<=n;i++){
        G[i].clear();
        c[i]=0;
        inq[i]=0;
        dis[i]=INF;
    }

    for(int i=1;i<=n;i++){
        if(!unk[i]){
            G[0].push_back({i,o[i]});
            G[i].push_back({0,-o[i]});
        }
        else {
            G[0].push_back({i,1e9});
            G[i].push_back({0,1e9});
        }
    }
    q.push(0);
    for(int i=1;i<=m;i++){
        G[b[i]].push_back({a[i],Val-1.0*d[i]});
     //   G[a[i]].push_back({b[i],Val+1.0*d[i]});
    }
    dis[0]=0;inq[0]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        if(c[x]>n)return 0;
        for(int i=0;i<G[x].size();i++){
            int to=G[x][i].first;
            double w=G[x][i].second;
            if( dis[to]>dis[x]+w){
                dis[to]=dis[x]+w;
                if(!inq[to]){
                    inq[to]=1;
                    ++c[to];
                    q.push(to);
                }
            }
        }
        inq[x]=0;
    }
    /*
    for(int i=1;i<=n;i++)printf("%.5f ",dis[i]);
    printf("\n");
    */
    return 1;
}
int w33ha(){
    for(int i=1;i<=n;i++){
        unk[i]=0;
        char s[34];
        scanf("%s",s+1);
        int l=strlen(s+1);
        if(s[1]=='?'){
            unk[i]=1;
            continue;
        }
        o[i]=0;
        int ss = 1,bb = 0;
        if(s[1] == '-') ss ++,bb = 1;
        for(int j=ss;j<=l;j++){
            o[i]=o[i]*10+s[j]-'0';
        }
        if(bb) o[i] = -o[i];
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i],&b[i],&d[i]);
    }
    double mid,l=0.0,r=1e9,ans=1e9;
    for(int i = 1;i <= 100;i ++) {
        mid=(l+r)/2.0;
        if(check(mid)){
            ans=mid;
            r=mid;
        }
        else{
            l=mid;
        }
    }
    printf("%.8f\n",ans);check(ans);
    for(int i=1;i<=n;i++){
        printf("%.8f",dis[i]);
        if(i==n)puts("");
        else printf(" ");
    }
    return 0;
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF)w33ha();
    return 0;
}
/*
2 2
? -2
1 2 3
2 1 1
3 0
? ? 3
*/
