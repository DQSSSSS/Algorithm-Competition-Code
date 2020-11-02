#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}


int n,m,k;
vector<int> ans;
int a[1010],b[1001],sum[1010][1010];
int r[1010],c[1010];
int rr[1000010],cc[1000010];
char mp[1010][1010];

void work() {
    int S = sum[n][m];

    if(S == 0) {
        for(int i = 0;i < k;i ++) ans.push_back(i+1); return ;
    }

    for(int A = 1;A <= n;A ++) if(!rr[sum[A][m]]) rr[sum[A][m]] = A;
    for(int A = 1;A <= n;A ++) {
        if(sum[A][m] == 0) continue;
        if(S % sum[A][m]) continue;
        bool flag = 0;
        for(int j = sum[A][m];j <= sum[n][m];j += sum[A][m]) {
            if(!rr[j]) { flag = 1; break; }
        }
        if(!flag) r[A] = 1;
    }

    for(int B = 1;B <= m;B ++) if(!cc[sum[n][B]]) cc[sum[n][B]] = B;
    for(int B = 1;B <= m;B ++) {
        if(sum[n][B] == 0) continue;
        if(S % sum[n][B]) continue;
        bool flag = 0;
        for(int j = sum[n][B];j <= sum[n][m];j += sum[n][B]) {
            if(!cc[j]) { flag = 1; break; }
        }
        if(!flag) c[B] = 1;
    }

    int A = -1,B = -1;
    for(int i = 1;i <= n;i ++) {
        if(!r[i]) continue;
        for(int j = 1;j <= m;j ++) {
            if(A != -1) break;
            if(!c[j]) continue;
            if(S / sum[i][m] - 1 + S / sum[n][j] - 1 != k) continue;
            if((S / sum[i][m]) * (S / sum[n][j]) * sum[i][j] != sum[n][m]) continue;
          //  cout << i << " " << j << endl;
            int flag = 1;
            for(int dx = sum[i][m],x = rr[dx];dx < S && flag;dx += sum[i][m],x = rr[dx]) {
                for(int dy = sum[n][j],y = cc[dy];dy < S && flag;dy += sum[n][j],y = cc[dy]) {
                    int nx = rr[dx+sum[i][m]];
                    int ny = cc[dy+sum[n][j]];
                    if(sum[nx][ny]-sum[x][ny]-sum[nx][y]+sum[x][y] != sum[i][j]) { flag = 0; }
                }
            }
            if(flag) A = i,B = j;
        }
        if(A != -1) break;
    }
/*
    for(int i = 1;i <= n;i ++) printf("%d ",r[i]); puts("");
    for(int i = 1;i <= m;i ++) printf("%d ",c[i]); puts("");
    cout << A << " " << B << endl;
*/
    if(A != -1) {
        for(int j = sum[A][m];j < sum[n][m];j += sum[A][m]) {
            ans.push_back(rr[j]);
        }

        for(int j = sum[n][B];j < sum[n][m];j += sum[n][B]) {
            ans.push_back(cc[j] + n - 1);
        }
    }
}

int main() {
    int T = read();
    while(T --) {
        n = read(),m = read(),k = read();
        for(int i = 1;i <= n;i ++) scanf("%s",mp[i] + 1);
        for(int i = 1;i <= max(n,m);i ++) a[i] = b[i] = 0;
        for(int i = 1;i <= max(n,m);i ++) r[i] = c[i] = 0;
        for(int i = 0;i <= n*m;i ++) rr[i] = cc[i] = 0;
        ans.clear();
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (mp[i][j] == '0');
                if(mp[i][j] == '0')
                    a[i] ++,b[j] ++;
            }
        }
        work();
        if(ans.size()) {
            assert(ans.size() == k);
            sort(ans.begin(),ans.end());
            for(int i = 0;i < ans.size();i ++)
                printf("%d%c",ans[i],i+1==ans.size() ? '\n' : ' ');
        }
        else {
            puts("Impossible");
        }
    }
}

/**

(a+1)*(b+1)*c=S

233
5 5 4
01010
10101
00000
11111
00000

6 7 2
1111111
1011101
1111111
1111111
1011101
1111111

5 6 2
111111
101110
111111
111111
101110

2 2 2
10
01

6 6 3
111101
101111
011101
101111
111101
111111

*/
