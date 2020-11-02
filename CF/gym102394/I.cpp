#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1e5+10;
const int mod=1e9+7;

int n;
int x[MAXN],y[MAXN],z[MAXN],num[MAXN],use[MAXN];

LL Fra(LL n){
    LL ret=1;
    for(int i=1;i<=n;i++) ret=(ret*i)%mod;
    return ret;
}

LL Power(LL a,LL b){
    LL ret=1;
    while(b){
        if (b%2==1){
            ret=(ret*a)%mod;
        }
        a=(a*a)%mod;
        b/=2;
    }
    return ret;
}

struct haha {
    int n;
    int tree[MAXN];

    void add(int x,int d) {
        x = n - x + 1;
        for(int i = x;i <= n;i += i & -i) tree[i] += d;
    }

    int ask(int x) {
        x = n - x + 1;
        int ans = 0;
        for(int i = x;i > 0;i -= i & -i) ans += tree[i];
        return ans;
    }

    void init(int nn) {
        n = nn;
        for(int i = 1;i <= n;i ++) tree[i] = 0;
    }
}tr;

pair<int,int> a[MAXN];

LL work() {
    if(y[1]!=1) return 0;
    if(y[n]!=n) return 0;
    int tot = 0;
    for(int i = 1;i <= n;i ++) use[i] = 0;
    for(int i = 1,j = 1;i <= n;i ++) {
        if(i == n || y[i] != y[i+1]) {
            a[++ tot] = make_pair(y[i],i-j+1);
            j = i + 1;
        }
    }
    tr.init(tot);
    for(int i = 1;i <= tot;i ++) {
        if(i != 1 && a[i-1].first > a[i].first) return 0;
        tr.add(i,a[i].second);
        use[a[i].first] = 1;
    }
    LL ans = 1;
    for(int i = n;i >= 1;i --) {
        int id = lower_bound(a+1,a+1+tot,make_pair(i,0))-a;
        //cout << i << " " << id << endl;
        int x = tr.ask(id);
        if(!use[i]) ans = ans * x % mod;
        tr.add(id,-1);
    }
   // cout << ans << endl;
    return ans;
}


LL Check(){
    LL ret=0;
    for(int i=1;i<=n;i++) z[i]=i;
    do {
        int mx=z[1],mn=z[1];
        int tag=1;
        if (x[1]!=0) tag=0;
        for(int i=2;i<=n;i++){
            mx=max(mx,z[i]);
            mn=min(mn,z[i]);
            if (mx-mn!=x[i]){
                tag=0;
                break;
            }
        }
        ret+=tag;
        if (tag==1){
            printf(":  ");for(int i=1;i<=n;i++) cout<<z[i]<<' ';
            cout<<endl;
        }
    }while(next_permutation(z+1,z+1+n));
    return ret;
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)x[i]=y[i]=z[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
            y[i]=x[i] + 1;
        }
        int cnt=unique(x+1,x+n+1)-(x+1);
        LL ans=work()*Power(2,cnt-1)%mod;
        printf("%lld\n",ans);
       // cout<<Check()<<endl;
    }
    return 0;
}
/*
233
3
0 0 2
3
0 1 1

10
0 1 4 4 5 7 7 7 9 9
*/
