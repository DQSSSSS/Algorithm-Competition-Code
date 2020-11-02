#include<bits/stdc++.h>
#define ll long long
#define LIM 50
using namespace std;
int n,q,A[100004];
struct seg{
    int l,r;
    vector<int>v;
}tr[400004];
vector<int>vec;
vector<int> Merge(vector<int> &a,vector<int> &b){
    //assert(a.size() <= LIM); assert(b.size() <= LIM);
    vector<int>g;
    g.clear();
    int ta=0,tb=0;
    while(ta<a.size()&&tb<b.size()&&g.size()<LIM){
        if(a[ta]>b[tb]){
            g.push_back(a[ta]);
            ta++;
        }
        else{
            g.push_back(b[tb]);
            tb++;
        }
    }
    while(ta<a.size()&&g.size()<LIM){
        g.push_back(a[ta]);ta++;
    }
    while(tb<b.size()&&g.size()<LIM){
        g.push_back(b[tb]);tb++;
    }
    //reverse(g.begin(),g.end());
    return g;
}
ll ask(){
  //  assert(vec.size() <= LIM);
    if(vec.size()<3)return -1LL;
    int t1=0,t2=1,t3=2;
    while(t3 < vec.size()){
        ll a=vec[t1],b=vec[t2],c=vec[t3];
        if(b+c>a)return b+c+a;
        ++t1;++t2;++t3;
    }
    return -1LL;
}
void build(int k,int l,int r){
    tr[k].l=l;tr[k].r=r;
    tr[k].v.clear();
    if(l==r){
        tr[k].v.push_back(A[l]);
        return ;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tr[k].v=Merge(tr[k<<1].v,tr[k<<1|1].v);
}

void query(int k,int a,int b){
    int l=tr[k].l,r=tr[k].r;
    //cout<<k<<" "<<" "<<a<<" "  <<b<<endl;
    if(a==l&&b==r){
        vec=Merge(vec,tr[k].v);
        return ;
    }
    int mid=(l+r)>>1;
    if(b<=mid)query(k<<1,a,b);
    else if(a>mid)query(k<<1|1,a,b);
    else{
        query(k<<1,a,mid);
        query(k<<1|1,mid+1,b);
    }
}
int w33ha(){
    for(int i=1;i<=n;i++)scanf("%d",&A[i]);
    build(1,1,n);
    //cout<<"F"<<endl;
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        //printf("%d %d\n",x,y);
        vec.clear();
        query(1,x,y);
        printf("%lld\n",ask());
    }
    return 0;
}

mt19937 rd(time(0));

int main(){
    /*int f[233] = {0};
    f[1] = 1; f[2] = 1;
    for(int i = 3;;i ++) {
        f[i] = f[i-1] + f[i-2];
        if(f[i] > 1e9) cout << i << endl;
    }
    freopen("11.in","w",stdout);
    int T = 4;
    while(T --) {
        n = 1e5,q = 1e5;
        printf("%d %d\n",n,q);
        for(int i = 1;i <= n;i ++) printf("%d ",rd() % (1000000001)); puts("");
        for(int i = 1;i <= q;i ++) {
            int l = rd() % n + 1;
            int r = rd() % n + 1;
            if(l>r) swap(l,r);
            printf("%d %d\n",l,r);
        }
    }
    freopen("11.in","r",stdin);*/
    while(scanf("%d%d",&n,&q)!=EOF)w33ha();
    return 0;
}

