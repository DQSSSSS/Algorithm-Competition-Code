#include<assert.h>
#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
 
typedef long long LL;
const int MAXN=1e6+10;
 
struct Node{
    Node(LL _x=0,LL _y=0):x(_x),y(_y),angle(atan2(y,x)){}    
    bool operator < (const Node node) const{
        return angle<node.angle;
    }
    LL x,y;
    double angle;
};
 
int n,m;
int bit[MAXN],lim[MAXN][2],ans[MAXN],nxt[MAXN],f[MAXN][2];
Node g[MAXN];
pair<pair<int,int>,int> q[MAXN];
map<Node,int> mp;
 
int query(int pos){
    int ret=0;
    for(int i=pos;i>0;i-=(i&-i)){
        ret+=bit[i];
    }
    return ret;
}
 
void update(int pos,int val){
    for(int i=pos;i<=1000000;i+=(i&-i)){
        bit[i]+=val;
    }
}
 
int main(){
    //freopen("3.in","r",stdin);
    //freopen("3.ans","w",stdout);
    scanf("%d",&n);
    int len=0;
    for(int i=1;i<=n;i++){
        int num; scanf("%d",&num);
        lim[i][0]=len+1;
        for(int j=1;j<=num;j++){
            int a,b; scanf("%d%d",&a,&b);
            f[j][0]=a; f[j][1]=b;
            if (j!=1){
                g[++len]=Node(f[j][0]-f[j-1][0],f[j][1]-f[j-1][1]);
            }
        }
        g[++len]=Node(f[1][0]-f[num][0],f[1][1]-f[num][1]);
        lim[i][1]=len;
    }
    memset(bit,0,sizeof(bit));
    memset(nxt,0,sizeof(nxt));
    for(int i=1;i<=len;i++){
        if (mp[g[i]]){
            nxt[mp[g[i]]]=i;
        } else{
            update(i,1);
        }
        mp[g[i]]=i;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int a,b; scanf("%d%d",&a,&b);
        q[i]=make_pair(make_pair(a,b),i);
    }
    sort(q+1,q+m+1);
    int lst=1;
    for(int i=1;i<=m;i++){
        for(;lst<q[i].first.first;lst++){
            for(int j=lim[lst][0];j<=lim[lst][1];j++){
                update(j,-1);
                if (nxt[j]!=0){
                    update(nxt[j],1);
                }
            }
        }
        int idx=q[i].second;
        int ql=q[i].first.first;
        int qr=q[i].first.second;
        ans[idx]=query(lim[qr][1]);
        int tmp=(lim[qr][1]-lim[ql][0]+1);
        //cout<<idx<<" "<<ans[idx]<<" "<<tmp<<endl;
        //assert(ans[idx]==tmp);
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
