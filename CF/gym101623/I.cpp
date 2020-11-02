#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

struct haha {
    int d,s,id;
}a[SZ];

vector<int> ans;
int pre[510][10010],n,c;
int f[510][10010];

void work() {
   // for(int i = 1;i <= n;i ++) printf("%d %d %d\n",a[i].d,a[i].s,a[i].id);
    for(int i = 1;i <= n;i ++) {
        for(int j = 0;j <= c;j ++) {
            f[i][j] = f[i-1][j];
            pre[i][j] = j;
            if(j >= a[i].s && j - a[i].s + max(a[i].s,a[i].d) <= c) {
                if(f[i][j] < f[i-1][j-a[i].s] + 1) {
                    f[i][j] = f[i-1][j-a[i].s] + 1;
                    pre[i][j] = j - a[i].s;
                //    printf("%d %d -> %d\n",i,j,pre[i][j]);
                }
            }
        }
    }
    vector<int> tmp;
    int j = 0;
    for(int i = 1;i <= c;i ++) if(f[n][i] > f[n][j]) j = i;
    for(int i = n;i >= 1;i --) {
        if(pre[i][j] < j) {
            tmp.push_back(a[i].id);
            j = pre[i][j];
        }
    }
    reverse(tmp.begin(),tmp.end());
    if(tmp.size() > ans.size()) ans = tmp;
}

bool cmp1(haha a,haha b) {
    if(a.s - max(a.s,a.d) != b.s - max(b.s,b.d))
        return a.s - max(a.s,a.d) < b.s - max(b.s,b.d);
    return a.s < b.s;
}

bool cmp2(haha a,haha b) {
    return a.s < b.s;
}

bool cmp3(haha a,haha b) {
    return a.d > b.d;
}

bool cmp4(haha a,haha b) {
    if(a.s - max(a.s,a.d) != b.s - max(b.s,b.d))
        return a.s - max(a.s,a.d) < b.s - max(b.s,b.d);
    return max(a.s,a.d) > max(b.s,b.d);
}

bool cmp5(haha a,haha b) {
    return a.d - a.s > b.d - b.s;
}

bool cmp6(haha a,haha b) {
    return max(a.s,a.d) > max(b.s,b.d);
}

bool cmp7(haha a,haha b) {
    if(a.s - max(a.s,a.d) != b.s - max(b.s,b.d))
        return a.s - max(a.s,a.d) < b.s - max(b.s,b.d);
    return a.d > b.d;
}

int main() {
    scanf("%d%d",&n,&c);
    for(int i = 1;i <= n;i ++) {
        scanf("%d%d",&a[i].d,&a[i].s);
        a[i].id = i;
    }
    sort(a+1,a+1+n,cmp1); work();
    sort(a+1,a+1+n,cmp2); work();
    sort(a+1,a+1+n,cmp3); work();
    sort(a+1,a+1+n,cmp4); work();
    sort(a+1,a+1+n,cmp5); work();
    sort(a+1,a+1+n,cmp6); work();
    sort(a+1,a+1+n,cmp7); work();
    printf("%d\n",ans.size());
    for(int x : ans) printf("%d ",x);
}
/*
3 7
5 1
6 2
7 3
*/
