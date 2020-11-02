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

int biao[50000][5][4],len = 0;
int tmp[5][4],lt[5];

void dfs(int now) {
    if(now == 13) {
        ++ len;
        for(int i = 1;i <= 4;i ++) {
            for(int j = 1;j <= 3;j ++) {
                biao[len][i][j] = tmp[i][j];
               // cout << tmp[i][j] << " ";
            }
         //   puts("");
        }
      //  puts("");
        return ;
    }
    for(int j = 1;j <= 4;j ++) {
        if(lt[j] == 3) continue;
        assert(lt[j] < 3);
        tmp[j][++ lt[j]] = now;
        dfs(now + 1);
        lt[j] --;
        if(lt[j] == 0) break;
    }
}

int a[33];

int check(int id) {
    int ans = 0;
    for(int i = 1;i <= 4;i ++)
        if(a[biao[id][i][1]] + a[biao[id][i][2]] > a[biao[id][i][3]])
            ans ++;
    return ans;
}

int main() {
    dfs(1);
    int T,cc = 0;
    scanf("%d",&T);
    while(T --) {
        for(int i = 1;i <= 12;i ++) {
            scanf("%d",&a[i]);
        }
        sort(a + 1,a + 1 + 12);
        int ans = 0,id = 0;
        for(int i = 1;i <= len;i ++) {
            int tmp = check(i);
            if(tmp > ans) {
                ans = tmp; id = i;
            }
        }
        printf("Case #%d: %d\n",++ cc,ans);
        for(int i = 1;i <= 4;i ++) {
            if(a[biao[id][i][1]] + a[biao[id][i][2]] > a[biao[id][i][3]])
                for(int j = 1;j <= 3;j ++) {
                    printf("%d",a[biao[id][i][j]]);
                    if(j == 3) printf("\n");
                    else printf(" ");
                }
        }
    }
    return 0;
}

