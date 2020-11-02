#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 +10;

struct TTT {
    int n;
    int a[SZ];

    void change(int x,int y) {
        x = n - x + 1;
        for(int i = x;i <= n;i += i & -i) a[i] = max(y,a[i]);
    }

    int ask(int x) {
        x = n - x + 1;
        int ans = 0;
        for(int i = x;i > 0;i -= i & -i) ans = max(ans,a[i]);
        return ans;
    }

    void init(int nn) {
        n = nn;
        for(int i = 1;i <= nn;i ++) a[i] = 0;
    }
}tree;

struct haha {
    int type,x,y,id;
}a[SZ];

int Ans[SZ];
int lsh[SZ];

int main(){
    int n,tot = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
        int x,y;
        scanf("%d%d",&x,&y);
        a[++ tot] = (haha){1,x,y,i};
        lsh[++ lsh[0]] = y;
    }
    int m;
    scanf("%d",&m);
    for(int i = 1;i <= m;i ++) {
        int x,y;
        scanf("%d%d",&x,&y);
        a[++ tot] = (haha){2,x,y,i};
        lsh[++ lsh[0]] = y;
    }
    sort(lsh+1,lsh+1+lsh[0]);
    lsh[0] = unique(lsh+1,lsh+1+lsh[0]) - lsh - 1;
    tree.init(lsh[0]);

    sort(a+1,a+1+tot, [](haha a,haha b) { return a.x==b.x?a.type>b.type:a.x>b.x; });
    for(int i = 1;i <= tot;i ++) {
        printf("%d %d %d %d\n",a[i].type,a[i].x,a[i].y,a[i].id);
        a[i].y = lower_bound(lsh+1,lsh+1+lsh[0],a[i].y)-lsh;
    }
    for(int i = 1;i <= tot;i ++) {
        if(a[i].type == 2) {
            tree.change(a[i].y,a[i].id);
        }
        else {
            int x = tree.ask(a[i].y);
            Ans[x] ++;
        }
    }
    for(int i = 1;i <= m;i ++) {
        printf("%d\n",Ans[i]);
    }
}
