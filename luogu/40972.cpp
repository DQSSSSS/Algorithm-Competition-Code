#include <bits/stdc++.h>
#define ls (p<<1)
#define rs (p<<1|1)
#define maxn 100001
#define mid ((l+r)>>1)
using namespace std;
struct Node{
    int l,r,id;
    double yl,yr;
    Node(int x1=0,int y1=0,int x2=0,int y2=0,int i=0){
        l=x1,r=x2;yl=y1,yr=y2;id=i;
        if (l==r) yl=yr=max(yl,yr);
    }
    double get(int x){return l==r?yl:yl+(k()*(x-l));}
    double k(){return (yr-yl)/(r-l);}
    void lm(int x){yl=get(x);l=x;}
    void rm(int x){yr=get(x);r=x;}
};
bool hei(Node a,Node b,int x){
    return a.get(x)==b.get(x)?a.id<b.id:a.get(x)>b.get(x);
}
struct St{
    Node tree[maxn*4];
    void build(int l,int r,int p){
        tree[p].l=l,tree[p].r=r;
        if (l==r) return;
        build(l,mid,ls);
        build(mid+1,r,rs);
    }
    Node query(int t,int l,int r,int p){
        if (l==r) return tree[p];Node tem;
        if (t<=mid) tem=query(t,l,mid,ls);
        else tem=query(t,mid+1,r,rs);
        return hei(tem,tree[p],t)?tem:tree[p];
    }
    void update(int l,int r,Node k,int p){
        if (tree[p].l>k.l) k.lm(tree[p].l);
        if (tree[p].r<k.r) k.rm(tree[p].r);
        if (hei(k,tree[p],mid)) swap(tree[p],k);
        if (min(tree[p].yl,tree[p].yr)>=max(k.yl,k.yr)) return;//如果在当前区间内没有交点就直接return
        if (l==r) return;
        if (tree[p].k()<=k.k()) update(mid+1,r,k,rs);//判断交点的位置
        else update(l,mid,k,ls);
    }
    void insert(int l,int r,Node k,int p){
        if (k.l>r||k.r<l) return;
        if (tree[p].l>k.l) k.lm(tree[p].l);
        if (tree[p].r<k.r) k.rm(tree[p].r);
        if (l==k.l&&r==k.r) {update(l,r,k,p);return;}//被完美地覆盖才更新区间的信息
        if (l==r) return;
        insert(l,mid,k,ls);insert(mid+1,r,k,rs);
    }
}T;
int la,Ind,n=39989;
int main(){
    ios::sync_with_stdio(false);
    T.build(1,n,1);
    int m;cin>>m;
    while(m--){
        int temp;cin>>temp;
        if (!temp){
            int k;cin>>k;
            k=(k+la-1)%39989+1;
            la=T.query(k,1,n,1).id;
            cout<<la<<endl;
        }
        else{
            int x0,x1,y1,y0;
            cin>>x0>>y0>>x1>>y1;
            x0=(x0+la-1)%39989+1;x1=(x1+la-1)%39989+1;
            y0=(y0+la-1)%(int)1e9+1;y1=(y1+la-1)%(int)1e9+1;//注意是1e9，而非题目所述的109
            if (x0>x1) swap(x0,x1),swap(y0,y1);
            Node tem=Node(x0,y0,x1,y1,++Ind);
            T.insert(1,n,tem,1);
        }
    }
}
