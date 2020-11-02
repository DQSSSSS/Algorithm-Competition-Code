#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
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

char a[SZ];
int k,n;
char S[SZ];
int top;
int b[SZ][27],L[27],R[27];

bool check(int a[27],int len,int b[27]) {
    int suml = 0,sumr = 0,sum = 0,s = 0;
    for(int i = 0;i < 26;i ++) {
        if(a[i] + b[i] < L[i]) return false;
        if(a[i] < L[i]) {
            sum += L[i] - a[i];
        }
        if(a[i] > R[i]) return false;
        s += min(b[i],R[i]-a[i]);
        suml += L[i];
        sumr += R[i];
    }
    if(s < len) return false;
    if(!(suml <= k && k <= sumr)) return false;
    if(sum > len) return false;
    return true;
}

char ans[SZ];

int main() {
    while(~scanf("%s%d",a,&k)) {
        for(int i = 0;i < 26;i ++) L[i] = read(),R[i] = read();
        int n = strlen(a);
        memset(b[n],0,sizeof b[n]);
        vector<int> g[27];
        for(int i = 0;i < n;i ++) g[a[i]-'a'].push_back(i);
        for(int i = n-1;i >= 0;i --) {
            for(int j = 0;j < 26;j ++) b[i][j] = b[i+1][j];
            b[i][a[i]-'a'] ++;
        }

        if(!check(b[n],k,b[0])) { puts("-1"); continue; }

        int nowid = -1;
        int h[27] = {},num[27] = {};
        for(int len = 0;len < k;len ++) {
            for(int i = 0;i < 26;i ++) {
                while(h[i] < g[i].size() && g[i][h[i]] <= nowid) h[i] ++;
                if(h[i] == g[i].size()) continue;
                int tmp[27] = {},id = g[i][h[i]];
                for(int j = 0;j < 26;j ++) tmp[j] = num[j];
                tmp[i] ++;
                if(check(tmp,k-len-1,b[id+1])) {
                   // printf("%d %d %d\n",len,i,id);
                    nowid = id;
                    ans[len] = i+'a';
                    num[i] ++;
                    break;
                }
            }
        }
        for(int i = 0;i < k;i ++) printf("%c",ans[i]); puts("");

    }
}

/**
acbabca 6
1 3
1 1
0 2
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 100
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
*/
