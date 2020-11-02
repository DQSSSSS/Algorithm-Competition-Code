#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int ans = 0;
int tmp[55][55],g[55][55],lt[55],lg[55];
int vis[22],a[22],fst[55],t,suf[55];

int nx[55];
int pr[55];

int del(int x) {
    pr[nx[x]] = pr[x];
    nx[pr[x]] = nx[x];
}

int ins(int x) {
    pr[nx[x]] = x;
    nx[pr[x]] = x;
}

void dfs(int now,int num) {
    if(ans == 4) return ;
    if(lt[num] == 3) {
        if(num > ans) {
            ans = num;
            for(int i = 1;i <= num;i ++) {
                lg[i] = 0;
                for(int j = 1;j <= 3;j ++) {
                    g[i][++ lg[i]] = a[tmp[i][j]];
                }
            }
        }
        num ++;
        lt[num] = 0;
    }
    if((12 - t + lt[num]) / 3 + num <= ans) return ;
    if(lt[num] == 2) {
        if(pr[0] <= tmp[num][2]) return ;
    }
    if(lt[num] == 1) {
        if(a[tmp[num][1]] <= suf[tmp[num][1]]) return ;
    }
    if(now == 13) return ;
    for(int i = now;i;i = nx[i]) {
        if(vis[i]) continue;
        if(lt[num] < 2) {
            vis[i] = num;
            tmp[num][++ lt[num]] = i;
            if(lt[num] == 1) fst[num] = i;
            t ++;
            del(i);
            dfs(i + 1,num);
            ins(i);
            t --;
            if(lt[num] == 1) fst[num] = 0;
            vis[i] = 0;
            lt[num] --;
        }
        else if(a[tmp[num][1]] + a[tmp[num][2]] > a[i]) {
           // assert(lt[num] == 2);
            vis[i] = num;
            tmp[num][++ lt[num]] = i;
            t ++;
            del(i);
            dfs(fst[num-1] + 1,num);
            ins(i);
            t --;
            vis[i] = 0;
            lt[num] --;
        }
    }
}

int main() {
    int T,cc = 0;
    scanf("%d",&T);
    while(T --) {
        for(int i = 1;i <= 12;i ++) {
            scanf("%d",&a[i]);
            vis[i] = 0;
            lt[i] = lg[i] = 0;
            fst[i] = 0;
            suf[i] = 0;
        }
        sort(a + 1,a + 1 + 12);
        for(int i = 10,minn = a[12] - a[11];i >= 1;i --)
            suf[i] = minn,minn = min(minn,a[i + 1] - a[i]);
        ans = 0;
        t = 0;
        for(int i = 0;i <= 12;i ++) nx[i] = i + 1;
        for(int i = 0;i <= 12;i ++) pr[i] = i - 1;
        nx[12] = 0; pr[0] = 12;
       /* for(int i = 1;i <= 12;i ++) cout << vis[i] << " "; puts("");
        for(int i = 1;i <= 12;i ++) cout << a[i] << " "; puts("");
        for(int i = 1;i <= 3;i ++) cout << lt[i] << " "; puts("");
        for(int i = 1;i <= 3;i ++) cout << lg[i] << " "; puts("");*/
        dfs(1,1);
        printf("Case #%d: %d\n",++ cc,ans);
        for(int i = 1;i <= ans;i ++) {
            //assert(lg[i] == 3);
            for(int j = 1;j <= lg[i];j ++) {
                printf("%d",g[i][j]);
                if(j == lg[i]) printf("\n");
                else printf(" ");
            }
//            puts("");
        }
    }
    return 0;
}
/**
233
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 2 2 2 2 2 2
1 1 2 3 5 8 13 21 34 55 89 144
1 1 2 3 5 8 13 21 34 55 89 14
5 3 2 6 8 4 9 6 3 2 1 3
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
1 2 4 8 16 32 64 128 256 512 1024 2048
1 2 4 8 16 32 64 128 256 512 1024 204
1 2 4 8 16 32 64 128 256 512 1024 204
5 6 200 205 206 209 5000 10000 15000 25000 40000 65000
*/
