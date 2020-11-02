#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e5 + 10;
const int MAXN=10005;

int n,q,k;
int x[MAXN];

struct Node{
	Node(){memset(bas,0,sizeof(bas));}
	int bas[15];
};

Node seg[4*MAXN];

Node merge(Node a,Node b){
	Node ret;
	for(int i=0;i<=14;i++) ret.bas[i]=a.bas[i];
	for(int i=1;i<15;i++){
		int tmp=b.bas[i];
		for(int j=i;j>=1;j--){
			if (tmp==0) break;
			if ((tmp & (1<<(j-1)))==0) continue;
			if (ret.bas[j]==0){
				ret.bas[j]=tmp;
				break;
			}
			tmp^=ret.bas[j];
		}
	}
	return ret;
}

void build(int u,int l,int r){
	if (l==r){
		for(int i=14;i>=1;i--)
			if ((x[l] & (1<<(i-1)))!=0){
				seg[u].bas[i]=x[l];
				break;
			}
		return;
	}
	int mid=(l+r)/2;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	seg[u]=merge(seg[u*2],seg[u*2+1]);
}

Node query(int u,int l,int r,int ql,int qr){
	if (l==ql && r==qr) return seg[u];
	int mid=(l+r)/2;
	if (qr<=mid) return query(u*2,l,mid,ql,qr);
	else{
		if (ql>mid) return query(u*2+1,mid+1,r,ql,qr);
		else return merge(query(u*2,l,mid,ql,mid),query(u*2+1,mid+1,r,mid+1,qr));
	}
}

int ask(int l,int r){
	Node ret=query(1,1,n,l,r);
	int mx=0;
	for(int i=14;i>=1;i--){
		if (ret.bas[i]==0) continue;
		if ((mx & (1<<(i-1)))==0) mx^=ret.bas[i]; 
	}
	return mx;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
		scanf("%d%d%d",&n,&q,&k);
		for(int i = 1;i <= n;i ++) scanf("%lld",&x[i]);
		build(1,1,n);
		for(int i=1;i<=q;i++){
			int a,b; scanf("%d%d",&a,&b);
			int ans=k | ask(a,b);
			printf("%d\n",ans);	
		}
	}
	return 0;
}
/**
3
3 2
1 2 1
6 3
1 5 3 4 7 6
9 4
2 7 1 3 6 5 8 9 4
*/
