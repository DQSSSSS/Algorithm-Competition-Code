#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN=3e5+10;
const double eps=1e-7;

int n,m;

struct Node{
    Node(int a,int b):a(a),b(b){}
    bool operator < (const Node& n) const{
        return a<n.a;
    }
    int a,b;
};
vector<Node> f;

bool check(int lim){
    if(f[0].a == 0 && 2*f[0].b > lim) return false;
    int p1 = -1,p2 = -1;
    for(int i = 0;i < n;i ++)
        if(2*f[i].b > lim) {
            p1 = i;
            break;
        }
    if(p1 == -1) return true;

    int maxn = f[p1].b,minn = f[p1].b;
    for(int i = p1 + 1;i < n;i ++) {
        if(max(maxn,f[i].b) - min(minn,f[i].b) > lim) { p2 = i; break; }
        maxn = max(maxn,f[i].b);
        minn = min(minn,f[i].b);
    }
    if(p2 == -1) return true;

   // cout << p1 << " -- " << p2 << endl;

    int l1 = maxn + minn;
    maxn = f[p2].b,minn = f[p2].b;
    for(int i = p2 + 1;i < n;i ++) {
        if(max(maxn,f[i].b) - min(minn,f[i].b) > lim) return false;
        maxn = max(maxn,f[i].b);
        minn = min(minn,f[i].b);
    }

    int l2 = maxn + minn;

    if(l2 < l1) {
        if(max(abs(2*maxn-l1),abs(2*minn-l1))>lim) return false;
    }
    return true;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b; scanf("%d%d",&a,&b);
        f.emplace_back(a,b);
    }
    sort(f.begin(),f.end());
    int l=-1,r=2e9,mid;
    //int l=0,r=4,mid;
    int ans;
    while(r-l>1){
        mid=(l+r)/2;
        if (check(mid)){
            ans=mid;
            r=mid;
        }
        else l=mid;
    }
    //for(int i = 0;i <= 6;i ++) cout << i << " " << check(i) << endl;
//    if (check(l)) ans=min(ans,l);
    double ret=0.5*r;
    printf("%.1f\n",ret);
    return 0;
}

/**
2
1 5
5 2

5
0 0
2 1
3 5
6 7
7 11

10
5 9
8 9
0 0
23 18
26 18
2 0
3 0
13 9
18 9
21 18
*/
